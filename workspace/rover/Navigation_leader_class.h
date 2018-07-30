/*----------------------------------------------------------------------------
 * File:  Navigation_leader_class.h
 *
 * Class:       leader  (leader)
 * Component:   Navigation
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef NAVIGATION_LEADER_CLASS_H
#define NAVIGATION_LEADER_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   leader  (leader)
 */
struct Navigation_leader {
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
  i_t id;  /* - id */
  r_t distance;  /* - distance */
  /* relationship storage */
  Navigation_rover * rover_R1;
};

void Navigation_leader_R1_Link( Navigation_rover *, Navigation_leader * );
/* Note:  No rover<-R1->leader unrelate accessor needed.  */

#define Navigation_leader_MAX_EXTENT_SIZE 200
extern Escher_Extent_t pG_Navigation_leader_extent;

/*
 * instance event:  leader1:'init'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Navigation_leaderevent1;
extern const Escher_xtUMLEventConstant_t Navigation_leaderevent1c;
/*
 * instance event:  leader2:'go'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Navigation_leaderevent2;
extern const Escher_xtUMLEventConstant_t Navigation_leaderevent2c;
/*
 * union of events targeted towards 'leader' state machine
 */
typedef union {
  Navigation_leaderevent1 leader1_1;  
  Navigation_leaderevent2 leader2_2;  
} Navigation_leader_Events_u;
/*
 * enumeration of state model states for class
 */
#define Navigation_leader_STATE_1 1  /* state [1]:  (start) */
#define Navigation_leader_STATE_2 2  /* state [2]:  (init) */
#define Navigation_leader_STATE_3 3  /* state [3]:  (polling) */
/*
 * enumeration of state model event numbers
 */
#define NAVIGATION_LEADEREVENT1NUM 0  /* leader1:'init' */
#define NAVIGATION_LEADEREVENT2NUM 1  /* leader2:'go' */
extern void Navigation_leader_Dispatch( Escher_xtUMLEvent_t * );

#ifdef	__cplusplus
}
#endif

#endif  /* NAVIGATION_LEADER_CLASS_H */
