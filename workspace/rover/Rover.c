/*----------------------------------------------------------------------------
 * File:  Rover.c
 *
 * UML Component Port Messages
 * Component/Module Name:  Rover
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "Rover_sys_types.h"
#include "Rover.h"
#include "TIM_bridge.h"
#include "EV3B_bridge.h"
#include "EV3M_bridge.h"
#include "EV3COL_bridge.h"
#include "EV3GYR_bridge.h"
#include "EV3ULS_bridge.h"
#include "EV3TCH_bridge.h"
#include "LOG_bridge.h"
#include "Navigation.h"
#include "RComm.h"

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  brake
 */
void
Rover_Navigation__CTL_brake( const i_t p_power )
{
  /* RComm::brake(power:PARAM.power) */
  Rover_RComm_brake( p_power );
}

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  incrementPower
 */
void
Rover_Navigation__CTL_incrementPower( const i_t p_power )
{
  /* RComm::incrementPower(power:PARAM.power) */
  Rover_RComm_incrementPower( p_power );
}

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  pollLeaderDistance
 */
void
Rover_Navigation__CTL_pollLeaderDistance()
{
  /* RComm::pollLeaderDistance() */
  Rover_RComm_pollLeaderDistance();
}

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  pollLeaderGPS
 */
void
Rover_Navigation__CTL_pollLeaderGPS()
{
  /* RComm::pollLeaderGPS() */
  Rover_RComm_pollLeaderGPS();
}

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  pollRoverCompass
 */
void
Rover_Navigation__CTL_pollRoverCompass()
{
  /* RComm::pollRoverCompass() */
  Rover_RComm_pollRoverCompass();
}

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  pollRoverGPS
 */
void
Rover_Navigation__CTL_pollRoverGPS()
{
  /* RComm::pollRoverGPS() */
  Rover_RComm_pollRoverGPS();
}

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  ready
 */
void
Rover_Navigation__CTL_ready()
{
  /* RComm::ready() */
  Rover_RComm_ready();
}

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  setForwardPower
 */
void
Rover_Navigation__CTL_setForwardPower( const i_t p_power )
{
  /* RComm::setForwardPower(power:PARAM.power) */
  Rover_RComm_setForwardPower( p_power );
}

/*
 * Interface:  Control
 * Provided Port:  Navigation__CTL
 * To Provider Message:  setLRPower
 */
void
Rover_Navigation__CTL_setLRPower( const i_t p_lpower, const i_t p_rpower )
{
  /* RComm::setLRPower(lpower:PARAM.lpower, rpower:PARAM.rpower) */
  Rover_RComm_setLRPower( p_lpower, p_rpower );
}

/*
 * Interface:  Navigation
 * Required Port:  Navigation
 * To Provider Message:  leaderDistance
 */
void
Rover_Navigation_leaderDistance( const r_t p_dist )
{
  Navigation_Navigation_leaderDistance(  p_dist );
}

/*
 * Interface:  Navigation
 * Required Port:  Navigation
 * To Provider Message:  leaderGPS
 */
void
Rover_Navigation_leaderGPS( const r_t p_x, const r_t p_z )
{
  Navigation_Navigation_leaderGPS(  p_x, p_z );
}

/*
 * Interface:  Navigation
 * Required Port:  Navigation
 * To Provider Message:  roverCompass
 */
void
Rover_Navigation_roverCompass( const r_t p_degrees )
{
  Navigation_Navigation_roverCompass(  p_degrees );
}

/*
 * Interface:  Navigation
 * Required Port:  Navigation
 * To Provider Message:  roverGPS
 */
void
Rover_Navigation_roverGPS( const r_t p_x, const r_t p_z )
{
  Navigation_Navigation_roverGPS(  p_x, p_z );
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  brake
 */
void
Rover_RComm_brake( const i_t p_power )
{
  RComm_RComm_brake(  p_power );
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  incrementPower
 */
void
Rover_RComm_incrementPower( const i_t p_power )
{
  RComm_RComm_incrementPower(  p_power );
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  pollLeaderDistance
 */
void
Rover_RComm_pollLeaderDistance()
{
  RComm_RComm_pollLeaderDistance();
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  pollLeaderGPS
 */
void
Rover_RComm_pollLeaderGPS()
{
  RComm_RComm_pollLeaderGPS();
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  pollRoverCompass
 */
void
Rover_RComm_pollRoverCompass()
{
  RComm_RComm_pollRoverCompass();
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  pollRoverGPS
 */
void
Rover_RComm_pollRoverGPS()
{
  RComm_RComm_pollRoverGPS();
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  ready
 */
void
Rover_RComm_ready()
{
  RComm_RComm_ready();
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  setForwardPower
 */
void
Rover_RComm_setForwardPower( const i_t p_power )
{
  RComm_RComm_setForwardPower(  p_power );
}

/*
 * Interface:  RComm
 * Required Port:  RComm
 * To Provider Message:  setLRPower
 */
void
Rover_RComm_setLRPower( const i_t p_lpower, const i_t p_rpower )
{
  RComm_RComm_setLRPower(  p_lpower, p_rpower );
}

/*
 * Interface:  LocationData
 * Provided Port:  RComm__Location
 * To Provider Message:  leaderDistance
 */
void
Rover_RComm__Location_leaderDistance( const r_t p_dist )
{
  /* Navigation::leaderDistance(dist:PARAM.dist) */
  Rover_Navigation_leaderDistance( p_dist );
}

/*
 * Interface:  LocationData
 * Provided Port:  RComm__Location
 * To Provider Message:  leaderGPS
 */
void
Rover_RComm__Location_leaderGPS( const r_t p_x, const r_t p_z )
{
  /* Navigation::leaderGPS(x:PARAM.x, z:PARAM.z) */
  Rover_Navigation_leaderGPS( p_x, p_z );
}

/*
 * Interface:  LocationData
 * Provided Port:  RComm__Location
 * To Provider Message:  roverCompass
 */
void
Rover_RComm__Location_roverCompass( const r_t p_degrees )
{
  /* Navigation::roverCompass(degrees:PARAM.degrees) */
  Rover_Navigation_roverCompass( p_degrees );
}

/*
 * Interface:  LocationData
 * Provided Port:  RComm__Location
 * To Provider Message:  roverGPS
 */
void
Rover_RComm__Location_roverGPS( const r_t p_x, const r_t p_z )
{
  /* Navigation::roverGPS(x:PARAM.x, z:PARAM.z) */
  Rover_Navigation_roverGPS( p_x, p_z );
}
