/*----------------------------------------------------------------------------
 * File:  Navigation_leader_class.c
 *
 * Class:       leader  (leader)
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
 * RELATE rover TO leader ACROSS R1
 */
void
Navigation_leader_R1_Link( Navigation_rover * supertype, Navigation_leader * subtype )
{
  if ( (supertype == 0) || (subtype == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "leader", "Navigation_leader_R1_Link" );
    return;
  }
  /* Optimized linkage for leader->rover[R1] */
  subtype->rover_R1 = supertype;
  /* Optimized linkage for rover->leader[R1] */
  supertype->R1_subtype = subtype;
  supertype->R1_object_id = Navigation_leader_CLASS_NUMBER;
}

/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s Navigation_leader_container[ Navigation_leader_MAX_EXTENT_SIZE ];
static Navigation_leader Navigation_leader_instances[ Navigation_leader_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_Navigation_leader_extent = {
  {0}, {0}, &Navigation_leader_container[ 0 ],
  (Escher_iHandle_t) &Navigation_leader_instances,
  sizeof( Navigation_leader ), Navigation_leader_STATE_1, Navigation_leader_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      leader  (leader)
 * Component:  Navigation
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [start]
 */
static void Navigation_leader_act1( Navigation_leader *, const Escher_xtUMLEvent_t * const );
static void
Navigation_leader_act1( Navigation_leader * self, const Escher_xtUMLEvent_t * const event )
{
}

/*
 * State 2:  [init]
 */
static void Navigation_leader_act2( Navigation_leader *, const Escher_xtUMLEvent_t * const );
static void
Navigation_leader_act2( Navigation_leader * self, const Escher_xtUMLEvent_t * const event )
{
  /* LOG::LogInfo( message:state init ) */
  LOG_LogInfo( "state init" );
  /* CTL::pollLeaderGPS() */
  Navigation_CTL_pollLeaderGPS();
  /* CTL::pollLeaderDistance() */
  Navigation_CTL_pollLeaderDistance();
  /* CTL::pollRoverGPS() */
  Navigation_CTL_pollRoverGPS();
  /* CTL::pollRoverCompass() */
  Navigation_CTL_pollRoverCompass();
  /* GENERATE leader1:init() TO self */
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Navigation_leaderevent1c );
    Escher_SendSelfEvent( e );
  }
}

/*
 * State 3:  [polling]
 */
static void Navigation_leader_act3( Navigation_leader *, const Escher_xtUMLEvent_t * const );
static void
Navigation_leader_act3( Navigation_leader * self, const Escher_xtUMLEvent_t * const event )
{
  /* IF ( ( self.id != 2 ) ) */
  if ( ( ((Navigation_leader *)xtUML_detect_empty_handle( self, "leader", "self.id" ))->id != 2 ) ) {
    Escher_Timer_t * t;Escher_xtUMLEvent_t * e;Navigation_follower * follower=0;
    /* ASSIGN self.id = 2 */
    ((Navigation_leader *)xtUML_detect_empty_handle( self, "leader", "self.id" ))->id = 2;
    /* LOG::LogInfo( message:Starting the rover. ) */
    LOG_LogInfo( "Starting the rover." );
    /* SELECT any follower FROM INSTANCES OF follower */
    follower = (Navigation_follower *) Escher_SetGetAny( &pG_Navigation_follower_extent.active );
    /* CREATE EVENT INSTANCE e(  ) TO follower */
    e = Escher_NewxtUMLEvent( (void *) follower, &Navigation_followerevent1c );
    /* ASSIGN t = TIM::timer_start_recurring(event_inst:e, microseconds:( MOVEMENT_FREQUENCY_MS * 1000 )) */
    t = TIM_timer_start_recurring( (Escher_xtUMLEvent_t *)e, ( 600 * 1000 ) );
  }
  /* CTL::pollLeaderGPS() */
  Navigation_CTL_pollLeaderGPS();
  /* CTL::pollLeaderDistance() */
  Navigation_CTL_pollLeaderDistance();
  /* CTL::pollRoverGPS() */
  Navigation_CTL_pollRoverGPS();
  /* CTL::pollRoverCompass() */
  Navigation_CTL_pollRoverCompass();
}

const Escher_xtUMLEventConstant_t Navigation_leaderevent1c = {
  Navigation_DOMAIN_ID, Navigation_leader_CLASS_NUMBER, NAVIGATION_LEADEREVENT1NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Navigation_leaderevent2c = {
  Navigation_DOMAIN_ID, Navigation_leader_CLASS_NUMBER, NAVIGATION_LEADEREVENT2NUM,
  ESCHER_IS_INSTANCE_EVENT };


/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t Navigation_leader_StateEventMatrix[ 3 + 1 ][ 2 ] = {
  /* row 0:  uninitialized state (for creation events) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 1:  Navigation_leader_STATE_1 (start) */
  { Navigation_leader_STATE_2, EVENT_IS_IGNORED },
  /* row 2:  Navigation_leader_STATE_2 (init) */
  { Navigation_leader_STATE_3, EVENT_IS_IGNORED },
  /* row 3:  Navigation_leader_STATE_3 (polling) */
  { EVENT_CANT_HAPPEN, Navigation_leader_STATE_3 }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t Navigation_leader_acts[ 4 ] = {
    (StateAction_t) 0,
    (StateAction_t) Navigation_leader_act1,  /* start */
    (StateAction_t) Navigation_leader_act2,  /* init */
    (StateAction_t) Navigation_leader_act3  /* polling */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 4 ] = {
    "",
    "start",
    "init",
    "polling"
  };

/*
 * instance state machine event dispatching
 */
void
Navigation_leader_Dispatch( Escher_xtUMLEvent_t * event )
{
  Escher_iHandle_t instance = GetEventTargetInstance( event );
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 3 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = Navigation_leader_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 3 ) {
        STATE_TXN_START_TRACE( "leader", current_state, state_name_strings[ current_state ] );
        /* Update the current state and execute the state action.  */
        instance->current_state = next_state;
        ( *Navigation_leader_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "leader", next_state, state_name_strings[ next_state ] );
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
          STATE_TXN_CH_TRACE( "leader", current_state );
      } else if ( next_state == EVENT_IS_IGNORED ) {
          /* event ignored */
          STATE_TXN_IG_TRACE( "leader", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

