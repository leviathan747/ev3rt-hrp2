/*--------------------------------------------------------------------------
 * File:  Rover_sys_main.c
 *
 * Description:  main, system initialization (and idle loop)
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "Rover_sys_types.h"
#include "Navigation_classes.h"

/*
 * Run application level initialization by initializing the
 * collection of instances for each class and calling domain
 * specific initialization.
 */
static void ApplicationLevelInitialization( void );
static void ApplicationLevelInitialization( void )
{
  Escher_DomainNumber_t d;
  Escher_ClassNumber_t c;
  const Escher_ClassNumber_t domain_class_count[ SYSTEM_DOMAIN_COUNT ] = {
    Navigation_MAX_CLASS_NUMBERS
  };
  for ( d = 0; d < SYSTEM_DOMAIN_COUNT; d++ ) {
    for ( c = 0; c < domain_class_count[ d ]; c++ ) {
      Escher_ClassFactoryInit( d, c );
    }
  }
	EV3B_Initialize();
}

/*
 *
 * main (although perhaps under a different name)
 *
 * Bring the system up and start the event dispatch loops.
 * Make invocations to the user hooks during the different phases
 * of bringup, run and shutdown.
 *
 */
int
xtUMLMain( int argc, char ** argv )
{
  UserInitializationCallout();
  Escher_SetFactoryInit( SYS_MAX_CONTAINERS );
  Escher_InitializeThreading();
  InitializeOoaEventPool();
  /* Initialize TIM.  To change this, copy TIM_bridge.c to the gen folder.  */
  #if ESCHER_SYS_MAX_XTUML_TIMERS > 0
  /* EV3 Timer is called by cyclic handler */
  /* TIM_init(); */
  #endif
  ApplicationLevelInitialization();
  UserPreOoaInitializationCallout();
  Navigation_execute_initialization();
  UserPostOoaInitializationCallout();
  Escher_xtUML_run(); /* This is the primary event dispatch loop.  */
  UserPreShutdownCallout();
  UserPostShutdownCallout();
  Escher_thread_shutdown();
  return 0;
}
