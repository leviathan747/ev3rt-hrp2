/*---------------------------------------------------------------------
 * File:  sys_thread.c
 *
 * Description:
 * This file provides implementation of multi-tasking/threading
 * capabilities allowing classes/subsystems to run in different
 * threads on a multi-tasking/threading OS/RTOS.
 *
 * your copyright statement can go here (from te_copyright.body)
 *-------------------------------------------------------------------*/
#include "ev3api.h"

/* EV3 HRP Headers */
#if defined (BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif


#include "Rover_sys_types.h"
#include "TIM_bridge.h"


static ER_ID mutexes[ SEMAPHORE_FLAVOR_MAX ];

typedef void (*TaskEntry)(void *);
static TaskEntry taskEntries[NUM_OF_XTUML_CLASS_THREADS];

/* Task table definition */
static ID nonbusy_wait_cond[NUM_OF_TOTAL_THREADS];

static ID threadnumber[NUM_OF_TOTAL_THREADS];

/*
 * Initialize those structures that need to be set up once at system
 * bring-up time.
 */
void Escher_InitializeThreading( void )
{
	int i=0;
	mutexes[i++] = mtxIQueue;
	mutexes[i++] = mtxSQueue;
	mutexes[i++] = mtxFreeList;
	mutexes[i++] = mtxNonBusy;
	mutexes[i++] = mtxInstance;
	mutexes[i++] = mtxTimer;
	mutexes[i++] = mtxILib;

	i=0;
	nonbusy_wait_cond[i++] = semWakeTaskMain; /* main */

	i=0;
	threadnumber[i++] = tMainTask; /* main */

}

/*
 * Obtain a resource lock so that this thread has mutually exclusive
 * access.
 */
void Escher_mutex_lock( const u1_t flavor )
{
  wai_sem( mutexes[ flavor ] );
}

/*
 * Release a resource lock that was obtained with the lock method.
 */
void Escher_mutex_unlock( const u1_t flavor )
{
  sig_sem( mutexes[ flavor ] );
}

/*
 * Go into a non-busy wait state waiting on someone to wake us
 * up with the nonbusy_wake method.
 */
void Escher_nonbusy_wait( const u1_t thread )
{

    ID semID = nonbusy_wait_cond[ thread ];
	wai_sem(semID);

}

/*
 * Wake up a thread that went to sleep waiting for something to happen.
 */
void Escher_nonbusy_wake( const u1_t thread )
{
    ID semID = nonbusy_wait_cond[ thread ];
    sig_sem(semID);
}

/*
 * Create and spin off a task/thread to run the input routine.
 */
void Escher_thread_create( void *(routine)(void *), const u1_t i )
{
	taskEntries[i] = (TaskEntry)routine;
    act_tsk(threadnumber[ i ] );
}

/*
 * Cleanup the structures initialized in Escher_InitializeThreading.
 */
 extern int Escher_run_flag;
void Escher_thread_shutdown( void )
{
	Escher_run_flag = false;
}

/*
 * The root function of tasks except main task.
 */
void runTask(const u1_t i)
{
	TaskEntry fp = taskEntries[i];
	if ( fp ) {
		(*fp)((void*)&i);
	}

}

extern void xtUMLMain(void);

/* The main task entry of xtUML */
/* This task will be spawned automatically by cfg file definition */
void main_task(intptr_t extinf) {
	/* 1msec alarm for TIM start */
	ev3_sta_cyc(xtUMLAlarm);

	/* entry point of xtUML */
	xtUMLMain();
}


/* Cyclic Handler */
void cyclic_handler(intptr_t extinf)
	{
	TIM_tick();
	}


