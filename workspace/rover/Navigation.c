/*----------------------------------------------------------------------------
 * File:  Navigation.c
 *
 * UML Component Port Messages
 * Component/Module Name:  Navigation
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "Rover_sys_types.h"
#include "Navigation.h"
#include "TIM_bridge.h"
#include "EV3B_bridge.h"
#include "EV3M_bridge.h"
#include "EV3COL_bridge.h"
#include "EV3GYR_bridge.h"
#include "EV3ULS_bridge.h"
#include "EV3TCH_bridge.h"
#include "LOG_bridge.h"
#include "Rover.h"
#include "Navigation_classes.h"

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  brake
 */
void
Navigation_CTL_brake( const i_t p_power )
{
  Rover_Navigation__CTL_brake(  p_power );
}

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  incrementPower
 */
void
Navigation_CTL_incrementPower( const i_t p_power )
{
  Rover_Navigation__CTL_incrementPower(  p_power );
}

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  pollLeaderDistance
 */
void
Navigation_CTL_pollLeaderDistance()
{
  Rover_Navigation__CTL_pollLeaderDistance();
}

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  pollLeaderGPS
 */
void
Navigation_CTL_pollLeaderGPS()
{
  Rover_Navigation__CTL_pollLeaderGPS();
}

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  pollRoverCompass
 */
void
Navigation_CTL_pollRoverCompass()
{
  Rover_Navigation__CTL_pollRoverCompass();
}

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  pollRoverGPS
 */
void
Navigation_CTL_pollRoverGPS()
{
  Rover_Navigation__CTL_pollRoverGPS();
}

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  ready
 */
void
Navigation_CTL_ready()
{
  Rover_Navigation__CTL_ready();
}

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  setForwardPower
 */
void
Navigation_CTL_setForwardPower( const i_t p_power )
{
  Rover_Navigation__CTL_setForwardPower(  p_power );
}

/*
 * Interface:  Control
 * Required Port:  CTL
 * To Provider Message:  setLRPower
 */
void
Navigation_CTL_setLRPower( const i_t p_lpower, const i_t p_rpower )
{
  Rover_Navigation__CTL_setLRPower(  p_lpower, p_rpower );
}

/*
 * Interface:  Navigation
 * Provided Port:  Navigation
 * To Provider Message:  leaderDistance
 */
void
Navigation_Navigation_leaderDistance( const r_t p_dist )
{
  Navigation_leader * leader=0;
  /* SELECT any leader FROM INSTANCES OF leader */
  leader = (Navigation_leader *) Escher_SetGetAny( &pG_Navigation_leader_extent.active );
  /* ASSIGN leader.distance = PARAM.dist */
  ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance = p_dist;
}

/*
 * Interface:  Navigation
 * Provided Port:  Navigation
 * To Provider Message:  leaderGPS
 */
void
Navigation_Navigation_leaderGPS( const r_t p_x, const r_t p_z )
{
  Navigation_leader * leader=0;Navigation_rover * leaderRover=0;
  /* SELECT any leader FROM INSTANCES OF leader */
  leader = (Navigation_leader *) Escher_SetGetAny( &pG_Navigation_leader_extent.active );
  /* SELECT one leaderRover RELATED BY leader->rover[R1] */





  leaderRover = ( 0 != leader ) ? leader->rover_R1 : 0;
  /* ASSIGN leaderRover.curPosition.x = PARAM.x */
  ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x = p_x;
  /* ASSIGN leaderRover.curPosition.z = PARAM.z */
  ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.z = p_z;
}

/*
 * Interface:  Navigation
 * Provided Port:  Navigation
 * To Provider Message:  roverCompass
 */
void
Navigation_Navigation_roverCompass( const r_t p_degrees )
{
  Navigation_follower * follower=0;
  /* SELECT any follower FROM INSTANCES OF follower */
  follower = (Navigation_follower *) Escher_SetGetAny( &pG_Navigation_follower_extent.active );
  /* ASSIGN follower.bearing = PARAM.degrees */
  ((Navigation_follower *)xtUML_detect_empty_handle( follower, "follower", "follower.bearing" ))->bearing = p_degrees;
}

/*
 * Interface:  Navigation
 * Provided Port:  Navigation
 * To Provider Message:  roverGPS
 */
void
Navigation_Navigation_roverGPS( const r_t p_x, const r_t p_z )
{
  Navigation_follower * follower=0;Navigation_rover * followerRover=0;
  /* SELECT any follower FROM INSTANCES OF follower */
  follower = (Navigation_follower *) Escher_SetGetAny( &pG_Navigation_follower_extent.active );
  /* SELECT one followerRover RELATED BY follower->rover[R1] */





  followerRover = ( 0 != follower ) ? follower->rover_R1 : 0;
  /* ASSIGN followerRover.curPosition.x = PARAM.x */
  ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.x = p_x;
  /* ASSIGN followerRover.curPosition.z = PARAM.z */
  ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.z = p_z;
}
/*
 * UML Domain Functions (Synchronous Services)
 */

/*
 * Domain Function:  testNavigation
 */
void
Navigation_testNavigation()
{
  Escher_Timer_t * t;Navigation_rover * rover1;Navigation_leader * leader;Navigation_rover * rover2;Navigation_follower * follower;Escher_xtUMLEvent_t * poller;
  /* CREATE OBJECT INSTANCE rover1 OF rover */
  rover1 = (Navigation_rover *) Escher_CreateInstance( Navigation_DOMAIN_ID, Navigation_rover_CLASS_NUMBER );
  /* CREATE OBJECT INSTANCE leader OF leader */
  leader = (Navigation_leader *) Escher_CreateInstance( Navigation_DOMAIN_ID, Navigation_leader_CLASS_NUMBER );
  /* RELATE leader TO rover1 ACROSS R1 */
  Navigation_leader_R1_Link( rover1, leader );
  /* ASSIGN leader.id = 1 */
  ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.id" ))->id = 1;
  /* CREATE OBJECT INSTANCE rover2 OF rover */
  rover2 = (Navigation_rover *) Escher_CreateInstance( Navigation_DOMAIN_ID, Navigation_rover_CLASS_NUMBER );
  /* CREATE OBJECT INSTANCE follower OF follower */
  follower = (Navigation_follower *) Escher_CreateInstance( Navigation_DOMAIN_ID, Navigation_follower_CLASS_NUMBER );
  /* RELATE follower TO rover2 ACROSS R1 */
  Navigation_follower_R1_Link( rover2, follower );
  /* GENERATE leader1:init() TO leader */
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( leader, &Navigation_leaderevent1c );
    Escher_SendEvent( e );
  }
  /* CREATE EVENT INSTANCE poller(  ) TO leader */
  poller = Escher_NewxtUMLEvent( (void *) leader, &Navigation_leaderevent2c );
  /* ASSIGN t = TIM::timer_start_recurring(event_inst:poller, microseconds:( POLLING_FREQUENCY_MS * 1000 )) */
  t = TIM_timer_start_recurring( (Escher_xtUMLEvent_t *)poller, ( 400 * 1000 ) );
  /* CTL::ready() */
  Navigation_CTL_ready();
}
/* xtUML class info (collections, sizes, etc.) */
Escher_Extent_t * const Navigation_class_info[ Navigation_MAX_CLASS_NUMBERS ] = {
  &pG_Navigation_leader_extent,
  &pG_Navigation_follower_extent,
  &pG_Navigation_rover_extent
};

/*
 * Array of pointers to the class event dispatcher method.
 * Index is the (model compiler enumerated) number of the state model.
 */
const EventTaker_t Navigation_EventDispatcher[ Navigation_STATE_MODELS ] = {
  Navigation_class_dispatchers
};

void Navigation_execute_initialization()
{
  /*
   * Initialization Function:  testNavigation
   * Component:  Navigation
   */
  Navigation_testNavigation();

}
