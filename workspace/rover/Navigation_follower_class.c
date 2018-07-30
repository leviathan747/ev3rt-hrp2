/*----------------------------------------------------------------------------
 * File:  Navigation_follower_class.c
 *
 * Class:       follower  (follower)
 * Component:   Navigation
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "Rover_sys_types.h"
#include "EV3B_bridge.h"
#include "EV3COL_bridge.h"
#include "EV3GYR_bridge.h"
#include "EV3M_bridge.h"
#include "EV3TCH_bridge.h"
#include "EV3ULS_bridge.h"
#include "LOG_bridge.h"
#include "TIM_bridge.h"
#include "Navigation_classes.h"


/*
 * RELATE rover TO follower ACROSS R1
 */
void
Navigation_follower_R1_Link( Navigation_rover * supertype, Navigation_follower * subtype )
{
  if ( (supertype == 0) || (subtype == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "follower", "Navigation_follower_R1_Link" );
    return;
  }
  /* Optimized linkage for follower->rover[R1] */
  subtype->rover_R1 = supertype;
  /* Optimized linkage for rover->follower[R1] */
  supertype->R1_subtype = subtype;
  supertype->R1_object_id = Navigation_follower_CLASS_NUMBER;
}

/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s Navigation_follower_container[ Navigation_follower_MAX_EXTENT_SIZE ];
static Navigation_follower Navigation_follower_instances[ Navigation_follower_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_Navigation_follower_extent = {
  {0}, {0}, &Navigation_follower_container[ 0 ],
  (Escher_iHandle_t) &Navigation_follower_instances,
  sizeof( Navigation_follower ), Navigation_follower_STATE_1, Navigation_follower_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      follower  (follower)
 * Component:  Navigation
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [start]
 */
static void Navigation_follower_act1( Navigation_follower *, const Escher_xtUMLEvent_t * const );
static void
Navigation_follower_act1( Navigation_follower * self, const Escher_xtUMLEvent_t * const event )
{
}

/*
 * State 2:  [calculatingMovement]
 */
static void Navigation_follower_act2( Navigation_follower *, const Escher_xtUMLEvent_t * const );
static void
Navigation_follower_act2( Navigation_follower * self, const Escher_xtUMLEvent_t * const event )
{
  r_t leaderToRoverXDiff;r_t leaderXDiff;bool leaderMovingRight;bool leaderMovingLeft;Navigation_leader * leader=0;Navigation_rover * leaderRover=0;Navigation_rover * followerRover=0;
  /* SELECT any leader FROM INSTANCES OF leader */
  leader = (Navigation_leader *) Escher_SetGetAny( &pG_Navigation_leader_extent.active );
  /* SELECT one leaderRover RELATED BY leader->rover[R1] */





  leaderRover = ( 0 != leader ) ? leader->rover_R1 : 0;
  /* SELECT one followerRover RELATED BY self->rover[R1] */





  followerRover = ( 0 != self ) ? self->rover_R1 : 0;
  /* LOG::LogInfo( message:------------------------------------------- ) */
  LOG_LogInfo( "-------------------------------------------" );
  /* LOG::LogReal( message:X Leader, r:leaderRover.curPosition.x ) */
  LOG_LogReal( "X Leader", ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x );
  /* LOG::LogReal( message:Z, r:leaderRover.curPosition.z ) */
  LOG_LogReal( "Z", ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.z );
  /* LOG::LogReal( message:X Follower, r:followerRover.curPosition.x ) */
  LOG_LogReal( "X Follower", ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.x );
  /* LOG::LogReal( message:Z, r:followerRover.curPosition.z ) */
  LOG_LogReal( "Z", ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.z );
  /* LOG::LogReal( message:Distance, r:leader.distance ) */
  LOG_LogReal( "Distance", ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance );
  /* LOG::LogInfo( message:------------------------------------------- ) */
  LOG_LogInfo( "-------------------------------------------" );
  /* ASSIGN leaderToRoverXDiff = ( leaderRover.curPosition.x - followerRover.curPosition.x ) */
  leaderToRoverXDiff = ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x - ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.x );
  /* ASSIGN leaderXDiff = ( leaderRover.curPosition.x - leaderRover.oldPosition.x ) */
  leaderXDiff = ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x - ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.oldPosition" ))->oldPosition.x );
  /* ASSIGN leaderMovingRight = FALSE */
  leaderMovingRight = FALSE;
  /* ASSIGN leaderMovingLeft = FALSE */
  leaderMovingLeft = FALSE;
  /* IF ( ( ( leaderRover.curPosition.x > leaderRover.prevPosition.x ) and ( leaderRover.prevPosition.x > leaderRover.oldPosition.x ) ) ) */
  if ( ( ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x > ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.prevPosition" ))->prevPosition.x ) && ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.prevPosition" ))->prevPosition.x > ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.oldPosition" ))->oldPosition.x ) ) ) {
    /* ASSIGN leaderMovingRight = TRUE */
    leaderMovingRight = TRUE;
  }
  else if ( ( ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x < ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.prevPosition" ))->prevPosition.x ) && ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.prevPosition" ))->prevPosition.x < ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.oldPosition" ))->oldPosition.x ) ) ) {
    /* ASSIGN leaderMovingLeft = TRUE */
    leaderMovingLeft = TRUE;
  }
  /* IF ( ( ( leaderToRoverXDiff > TRACK_PRECISION ) and ( leaderRover.curPosition.x > followerRover.curPosition.x ) ) ) */
  if ( ( ( leaderToRoverXDiff > 1.0 ) && ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x > ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.x ) ) ) {
    /* LOG::LogReal( message:CASE A - Leader to Rover X diff: , r:leaderToRoverXDiff ) */
    LOG_LogReal( "CASE A - Leader to Rover X diff: ", leaderToRoverXDiff );
    /* GENERATE follower4:turnRight() TO self */
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent4c );
      Escher_SendSelfEvent( e );
    }
  }
  else if ( ( ( leaderToRoverXDiff < -1.0 ) && ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x < ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.x ) ) ) {
    /* LOG::LogReal( message:CASE B - Leader to Rover X diff: , r:leaderToRoverXDiff ) */
    LOG_LogReal( "CASE B - Leader to Rover X diff: ", leaderToRoverXDiff );
    /* GENERATE follower3:turnLeft() TO self */
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent3c );
      Escher_SendSelfEvent( e );
    }
  }
  else if ( ( ( leaderXDiff > 0.2 ) && leaderMovingRight ) ) {
    /* LOG::LogReal( message:CASE C - Leader X diff: , r:leaderXDiff ) */
    LOG_LogReal( "CASE C - Leader X diff: ", leaderXDiff );
    /* GENERATE follower4:turnRight() TO self */
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent4c );
      Escher_SendSelfEvent( e );
    }
  }
  else if ( ( ( leaderXDiff < -0.2 ) && leaderMovingRight ) ) {
    /* LOG::LogReal( message:CASE D - distance: , r:leader.distance ) */
    LOG_LogReal( "CASE D - distance: ", ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance );
    /* GENERATE follower2:distance() TO self */
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent2c );
      Escher_SendSelfEvent( e );
    }
  }
  else if ( ( ( leaderXDiff < -0.2 ) && leaderMovingLeft ) ) {
    /* LOG::LogReal( message:CASE E - Leader X diff: , r:leaderXDiff ) */
    LOG_LogReal( "CASE E - Leader X diff: ", leaderXDiff );
    /* GENERATE follower3:turnLeft() TO self */
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent3c );
      Escher_SendSelfEvent( e );
    }
  }
  else if ( ( ( leaderXDiff > 0.2 ) && leaderMovingLeft ) ) {
    /* LOG::LogReal( message:CASE F - distance: , r:leader.distance ) */
    LOG_LogReal( "CASE F - distance: ", ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance );
    /* GENERATE follower2:distance() TO self */
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent2c );
      Escher_SendSelfEvent( e );
    }
  }
  else {
    /* LOG::LogReal( message:CASE G - distance: , r:leader.distance ) */
    LOG_LogReal( "CASE G - distance: ", ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance );
    /* GENERATE follower2:distance() TO self */
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent2c );
      Escher_SendSelfEvent( e );
    }
  }
}

/*
 * State 3:  [distancing]
 */
static void Navigation_follower_act3( Navigation_follower *, const Escher_xtUMLEvent_t * const );
static void
Navigation_follower_act3( Navigation_follower * self, const Escher_xtUMLEvent_t * const event )
{
  r_t leaderZDiff;Navigation_leader * leader=0;Navigation_rover * leaderRover=0;Navigation_rover * followerRover=0;
  /* SELECT any leader FROM INSTANCES OF leader */
  leader = (Navigation_leader *) Escher_SetGetAny( &pG_Navigation_leader_extent.active );
  /* SELECT one leaderRover RELATED BY leader->rover[R1] */





  leaderRover = ( 0 != leader ) ? leader->rover_R1 : 0;
  /* SELECT one followerRover RELATED BY self->rover[R1] */





  followerRover = ( 0 != self ) ? self->rover_R1 : 0;
  /* IF ( ( leader.distance < DIST_TOO_CLOSE ) ) */
  if ( ( ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance < 11.0 ) ) {
    /* LOG::LogInfo( message:Current distance way too close.  Stopping. ) */
    LOG_LogInfo( "Current distance way too close.  Stopping." );
    /* CTL::brake(power:100) */
    Navigation_CTL_brake( 100 );
  }
  else if ( ( ( ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance >= 11.0 ) && ( ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance < 12.25 ) ) ) {
    /* LOG::LogInfo( message:Current distance too close. Moving forward slowly. ) */
    LOG_LogInfo( "Current distance too close. Moving forward slowly." );
    /* CTL::brake(power:0) */
    Navigation_CTL_brake( 0 );
    /* CTL::setLRPower(lpower:5, rpower:5) */
    Navigation_CTL_setLRPower( 5, 5 );
  }
  else if ( ( ( ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance >= 14.5 ) && ( ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance < 25.0 ) ) ) {
    /* LOG::LogInfo( message:Current distance too far. Moving forward quickly. ) */
    LOG_LogInfo( "Current distance too far. Moving forward quickly." );
    /* CTL::brake(power:0) */
    Navigation_CTL_brake( 0 );
    /* CTL::setLRPower(lpower:75, rpower:75) */
    Navigation_CTL_setLRPower( 75, 75 );
  }
  else if ( ( ((Navigation_leader *)xtUML_detect_empty_handle( leader, "leader", "leader.distance" ))->distance >= 40.0 ) ) {
    /* LOG::LogInfo( message:Current distance way too far. Stopping. ) */
    LOG_LogInfo( "Current distance way too far. Stopping." );
    /* CTL::brake(power:100) */
    Navigation_CTL_brake( 100 );
  }
  else {
    /* LOG::LogInfo( message:In the zone, proceeding reasonably. ) */
    LOG_LogInfo( "In the zone, proceeding reasonably." );
    /* CTL::brake(power:0) */
    Navigation_CTL_brake( 0 );
    /* CTL::setLRPower(lpower:45, rpower:45) */
    Navigation_CTL_setLRPower( 45, 45 );
  }
  /* ASSIGN leaderZDiff = ( leaderRover.curPosition.z - leaderRover.prevPosition.z ) */
  leaderZDiff = ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.z - ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.prevPosition" ))->prevPosition.z );
  /* IF ( ( ( leaderZDiff >= 0 ) and ( followerRover.curPosition.z >= ( leaderRover.curPosition.z - 1 ) ) ) ) */
  if ( ( ( leaderZDiff >= 0 ) && ( ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.z >= ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.z - 1 ) ) ) ) {
    /* LOG::LogInfo( message:Stopping so we don't pass the leader. ) */
    LOG_LogInfo( "Stopping so we don't pass the leader." );
    /* CTL::brake(power:100) */
    Navigation_CTL_brake( 100 );
  }
  /* IF ( ( ( leaderZDiff < 0 ) and ( followerRover.curPosition.z <= ( leaderRover.curPosition.z + 1 ) ) ) ) */
  if ( ( ( leaderZDiff < 0 ) && ( ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.z <= ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.z + 1 ) ) ) ) {
    /* LOG::LogInfo( message:Stopping so we don't pass the leader. ) */
    LOG_LogInfo( "Stopping so we don't pass the leader." );
    /* CTL::brake(power:100) */
    Navigation_CTL_brake( 100 );
  }
  /* GENERATE follower5:doneMoving() TO self */
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent5c );
    Escher_SendSelfEvent( e );
  }
}

/*
 * State 4:  [init]
 */
static void Navigation_follower_act4( Navigation_follower *, const Escher_xtUMLEvent_t * const );
static void
Navigation_follower_act4( Navigation_follower * self, const Escher_xtUMLEvent_t * const event )
{
  /* GENERATE follower1:go() TO self */
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent1c );
    Escher_SendSelfEvent( e );
  }
}

/*
 * State 5:  [turningLeft]
 */
static void Navigation_follower_act5( Navigation_follower *, const Escher_xtUMLEvent_t * const );
static void
Navigation_follower_act5( Navigation_follower * self, const Escher_xtUMLEvent_t * const event )
{
  Navigation_leader * leader=0;Navigation_rover * leaderRover=0;Navigation_rover * followerRover=0;
  /* SELECT any leader FROM INSTANCES OF leader */
  leader = (Navigation_leader *) Escher_SetGetAny( &pG_Navigation_leader_extent.active );
  /* SELECT one leaderRover RELATED BY leader->rover[R1] */





  leaderRover = ( 0 != leader ) ? leader->rover_R1 : 0;
  /* SELECT one followerRover RELATED BY self->rover[R1] */





  followerRover = ( 0 != self ) ? self->rover_R1 : 0;
  /* IF ( ( leaderRover.curPosition.x < followerRover.curPosition.x ) ) */
  if ( ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x < ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.x ) ) {
    /* LOG::LogInfo( message:turningLeft ) */
    LOG_LogInfo( "turningLeft" );
    /* CTL::setLRPower(lpower:15, rpower:30) */
    Navigation_CTL_setLRPower( 15, 30 );
  }
  else {
    /* LOG::LogInfo( message:  Override, not turningLeft ) */
    LOG_LogInfo( "  Override, not turningLeft" );
    /* CTL::setLRPower(lpower:30, rpower:30) */
    Navigation_CTL_setLRPower( 30, 30 );
  }
  /* GENERATE follower5:doneMoving() TO self */
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent5c );
    Escher_SendSelfEvent( e );
  }
}

/*
 * State 6:  [turningRight]
 */
static void Navigation_follower_act6( Navigation_follower *, const Escher_xtUMLEvent_t * const );
static void
Navigation_follower_act6( Navigation_follower * self, const Escher_xtUMLEvent_t * const event )
{
  Navigation_leader * leader=0;Navigation_rover * leaderRover=0;Navigation_rover * followerRover=0;
  /* SELECT any leader FROM INSTANCES OF leader */
  leader = (Navigation_leader *) Escher_SetGetAny( &pG_Navigation_leader_extent.active );
  /* SELECT one leaderRover RELATED BY leader->rover[R1] */





  leaderRover = ( 0 != leader ) ? leader->rover_R1 : 0;
  /* SELECT one followerRover RELATED BY self->rover[R1] */





  followerRover = ( 0 != self ) ? self->rover_R1 : 0;
  /* IF ( ( leaderRover.curPosition.x > followerRover.curPosition.x ) ) */
  if ( ( ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition.x > ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition.x ) ) {
    /* LOG::LogInfo( message:turningRight ) */
    LOG_LogInfo( "turningRight" );
    /* CTL::setLRPower(lpower:30, rpower:15) */
    Navigation_CTL_setLRPower( 30, 15 );
  }
  else {
    /* LOG::LogInfo( message:  Override, not turningRight ) */
    LOG_LogInfo( "  Override, not turningRight" );
    /* CTL::setLRPower(lpower:30, rpower:30) */
    Navigation_CTL_setLRPower( 30, 30 );
  }
  /* GENERATE follower5:doneMoving() TO self */
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_followerevent5c );
    Escher_SendSelfEvent( e );
  }
}

/*
 * State 7:  [finalizingMovement]
 */
static void Navigation_follower_act7( Navigation_follower *, const Escher_xtUMLEvent_t * const );
static void
Navigation_follower_act7( Navigation_follower * self, const Escher_xtUMLEvent_t * const event )
{
  Navigation_leader * leader=0;Navigation_rover * leaderRover=0;Navigation_rover * followerRover=0;
  /* SELECT any leader FROM INSTANCES OF leader */
  leader = (Navigation_leader *) Escher_SetGetAny( &pG_Navigation_leader_extent.active );
  /* SELECT one leaderRover RELATED BY leader->rover[R1] */





  leaderRover = ( 0 != leader ) ? leader->rover_R1 : 0;
  /* SELECT one followerRover RELATED BY self->rover[R1] */





  followerRover = ( 0 != self ) ? self->rover_R1 : 0;
  /* ASSIGN leaderRover.oldPosition = leaderRover.prevPosition */
  ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.oldPosition" ))->oldPosition = ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.prevPosition" ))->prevPosition;
  /* ASSIGN leaderRover.prevPosition = leaderRover.curPosition */
  ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.prevPosition" ))->prevPosition = ((Navigation_rover *)xtUML_detect_empty_handle( leaderRover, "rover", "leaderRover.curPosition" ))->curPosition;
  /* ASSIGN followerRover.oldPosition = followerRover.prevPosition */
  ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.oldPosition" ))->oldPosition = ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.prevPosition" ))->prevPosition;
  /* ASSIGN followerRover.prevPosition = followerRover.curPosition */
  ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.prevPosition" ))->prevPosition = ((Navigation_rover *)xtUML_detect_empty_handle( followerRover, "rover", "followerRover.curPosition" ))->curPosition;
}

const Escher_xtUMLEventConstant_t Navigation_followerevent1c = {
  Navigation_DOMAIN_ID, Navigation_follower_CLASS_NUMBER, NAVIGATION_FOLLOWEREVENT1NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Navigation_followerevent2c = {
  Navigation_DOMAIN_ID, Navigation_follower_CLASS_NUMBER, NAVIGATION_FOLLOWEREVENT2NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Navigation_followerevent3c = {
  Navigation_DOMAIN_ID, Navigation_follower_CLASS_NUMBER, NAVIGATION_FOLLOWEREVENT3NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Navigation_followerevent4c = {
  Navigation_DOMAIN_ID, Navigation_follower_CLASS_NUMBER, NAVIGATION_FOLLOWEREVENT4NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Navigation_followerevent5c = {
  Navigation_DOMAIN_ID, Navigation_follower_CLASS_NUMBER, NAVIGATION_FOLLOWEREVENT5NUM,
  ESCHER_IS_INSTANCE_EVENT };


/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t Navigation_follower_StateEventMatrix[ 7 + 1 ][ 5 ] = {
  /* row 0:  uninitialized state (for creation events) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 1:  Navigation_follower_STATE_1 (start) */
  { Navigation_follower_STATE_4, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 2:  Navigation_follower_STATE_2 (calculatingMovement) */
  { EVENT_IS_IGNORED, Navigation_follower_STATE_3, Navigation_follower_STATE_5, Navigation_follower_STATE_6, EVENT_CANT_HAPPEN },
  /* row 3:  Navigation_follower_STATE_3 (distancing) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, Navigation_follower_STATE_7 },
  /* row 4:  Navigation_follower_STATE_4 (init) */
  { Navigation_follower_STATE_2, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 5:  Navigation_follower_STATE_5 (turningLeft) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, Navigation_follower_STATE_7 },
  /* row 6:  Navigation_follower_STATE_6 (turningRight) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, Navigation_follower_STATE_7 },
  /* row 7:  Navigation_follower_STATE_7 (finalizingMovement) */
  { Navigation_follower_STATE_2, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t Navigation_follower_acts[ 8 ] = {
    (StateAction_t) 0,
    (StateAction_t) Navigation_follower_act1,  /* start */
    (StateAction_t) Navigation_follower_act2,  /* calculatingMovement */
    (StateAction_t) Navigation_follower_act3,  /* distancing */
    (StateAction_t) Navigation_follower_act4,  /* init */
    (StateAction_t) Navigation_follower_act5,  /* turningLeft */
    (StateAction_t) Navigation_follower_act6,  /* turningRight */
    (StateAction_t) Navigation_follower_act7  /* finalizingMovement */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 8 ] = {
    "",
    "start",
    "calculatingMovement",
    "distancing",
    "init",
    "turningLeft",
    "turningRight",
    "finalizingMovement"
  };

/*
 * instance state machine event dispatching
 */
void
Navigation_follower_Dispatch( Escher_xtUMLEvent_t * event )
{
  Escher_iHandle_t instance = GetEventTargetInstance( event );
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 7 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = Navigation_follower_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 7 ) {
        STATE_TXN_START_TRACE( "follower", current_state, state_name_strings[ current_state ] );
        /* Update the current state and execute the state action.  */
        instance->current_state = next_state;
        ( *Navigation_follower_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "follower", next_state, state_name_strings[ next_state ] );
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
          STATE_TXN_CH_TRACE( "follower", current_state );
      } else if ( next_state == EVENT_IS_IGNORED ) {
          /* event ignored */
          STATE_TXN_IG_TRACE( "follower", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

