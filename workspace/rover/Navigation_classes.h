/*----------------------------------------------------------------------------
 * File:  Navigation_classes.h
 *
 * This file defines the object type identification numbers for all classes
 * in the component:  Navigation
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef NAVIGATION_CLASSES_H
#define NAVIGATION_CLASSES_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Initialization services for component:  Navigation
 */
extern Escher_Extent_t * const Navigation_class_info[];
extern const EventTaker_t Navigation_EventDispatcher[];
void Navigation_execute_initialization( void );

#define Navigation_STATE_MODELS 2
/* Define constants to map to class numbers.  */
#define Navigation_leader_CLASS_NUMBER 0
#define Navigation_follower_CLASS_NUMBER 1
#define Navigation_rover_CLASS_NUMBER 2
#define Navigation_MAX_CLASS_NUMBERS 3

/* Provide a map of classes to task numbers.  */
#define Navigation_TASK_NUMBERS  0, 0

#define Navigation_class_dispatchers\
  Navigation_leader_Dispatch,\
  Navigation_follower_Dispatch

/* Provide definitions of the shapes of the class structures.  */

typedef struct Navigation_leader Navigation_leader;
typedef struct Navigation_follower Navigation_follower;
typedef struct Navigation_rover Navigation_rover;

/* union of class declarations so we may derive largest class size */
#define Navigation_CLASS_U \
  char Navigation_dummy;\

/*
 * UML Domain Functions (Synchronous Services)
 */
void Navigation_testNavigation( void );

#include "TIM_bridge.h"
#include "EV3B_bridge.h"
#include "EV3M_bridge.h"
#include "EV3COL_bridge.h"
#include "EV3GYR_bridge.h"
#include "EV3ULS_bridge.h"
#include "EV3TCH_bridge.h"
#include "LOG_bridge.h"
#include "Navigation.h"
#include "Navigation_rover_class.h"
#include "Navigation_leader_class.h"
#include "Navigation_follower_class.h"
/*
 * roll-up of all events (with their parameters) for component Navigation
 */
typedef union {
  Navigation_leader_Events_u Navigation_leader_Events_u_namespace;
  Navigation_follower_Events_u Navigation_follower_Events_u_namespace;
} Navigation_DomainEvents_u;

#ifdef	__cplusplus
}
#endif
#endif  /* NAVIGATION_CLASSES_H */
