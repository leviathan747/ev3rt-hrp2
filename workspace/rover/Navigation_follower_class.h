/*----------------------------------------------------------------------------
 * File:  Navigation_follower_class.h
 *
 * Class:       follower  (follower)
 * Component:   Navigation
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef NAVIGATION_FOLLOWER_CLASS_H
#define NAVIGATION_FOLLOWER_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   follower  (follower)
 */
struct Navigation_follower {
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
  i_t id;  /* - id */
  r_t bearing;  /* - bearing */
  /* relationship storage */
  Navigation_rover * rover_R1;
};

void Navigation_follower_R1_Link( Navigation_rover *, Navigation_follower * );
/* Note:  No rover<-R1->follower unrelate accessor needed.  */

#define Navigation_follower_MAX_EXTENT_SIZE 200
extern Escher_Extent_t pG_Navigation_follower_extent;

/*
 * instance event:  follower1:'go'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Navigation_followerevent1;
extern const Escher_xtUMLEventConstant_t Navigation_followerevent1c;
/*
 * instance event:  follower2:'distance'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Navigation_followerevent2;
extern const Escher_xtUMLEventConstant_t Navigation_followerevent2c;
/*
 * instance event:  follower3:'turnLeft'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Navigation_followerevent3;
extern const Escher_xtUMLEventConstant_t Navigation_followerevent3c;
/*
 * instance event:  follower4:'turnRight'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Navigation_followerevent4;
extern const Escher_xtUMLEventConstant_t Navigation_followerevent4c;
/*
 * instance event:  follower5:'doneMoving'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Navigation_followerevent5;
extern const Escher_xtUMLEventConstant_t Navigation_followerevent5c;
/*
 * union of events targeted towards 'follower' state machine
 */
typedef union {
  Navigation_followerevent1 follower1_1;  
  Navigation_followerevent2 follower2_2;  
  Navigation_followerevent3 follower3_3;  
  Navigation_followerevent4 follower4_4;  
  Navigation_followerevent5 follower5_5;  
} Navigation_follower_Events_u;
/*
 * enumeration of state model states for class
 */
#define Navigation_follower_STATE_1 1  /* state [1]:  (start) */
#define Navigation_follower_STATE_2 2  /* state [2]:  (calculatingMovement) */
#define Navigation_follower_STATE_3 3  /* state [3]:  (distancing) */
#define Navigation_follower_STATE_4 4  /* state [4]:  (init) */
#define Navigation_follower_STATE_5 5  /* state [5]:  (turningLeft) */
#define Navigation_follower_STATE_6 6  /* state [6]:  (turningRight) */
#define Navigation_follower_STATE_7 7  /* state [7]:  (finalizingMovement) */
/*
 * enumeration of state model event numbers
 */
#define NAVIGATION_FOLLOWEREVENT1NUM 0  /* follower1:'go' */
#define NAVIGATION_FOLLOWEREVENT2NUM 1  /* follower2:'distance' */
#define NAVIGATION_FOLLOWEREVENT3NUM 2  /* follower3:'turnLeft' */
#define NAVIGATION_FOLLOWEREVENT4NUM 3  /* follower4:'turnRight' */
#define NAVIGATION_FOLLOWEREVENT5NUM 4  /* follower5:'doneMoving' */
extern void Navigation_follower_Dispatch( Escher_xtUMLEvent_t * );

#ifdef	__cplusplus
}
#endif

#endif  /* NAVIGATION_FOLLOWER_CLASS_H */
