/*----------------------------------------------------------------------------
 * File:  Rover.h
 *
 * UML Component (Module) Declaration (Operations and Signals)
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ROVER_H
#define ROVER_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
void Rover_Navigation__CTL_brake( const i_t );
void Rover_Navigation__CTL_incrementPower( const i_t );
void Rover_Navigation__CTL_pollLeaderDistance( void );
void Rover_Navigation__CTL_pollLeaderGPS( void );
void Rover_Navigation__CTL_pollRoverCompass( void );
void Rover_Navigation__CTL_pollRoverGPS( void );
void Rover_Navigation__CTL_ready( void );
void Rover_Navigation__CTL_setForwardPower( const i_t );
void Rover_Navigation__CTL_setLRPower( const i_t, const i_t );
void Rover_Navigation_leaderDistance( const r_t );
void Rover_Navigation_leaderGPS( const r_t, const r_t );
void Rover_Navigation_roverCompass( const r_t );
void Rover_Navigation_roverGPS( const r_t, const r_t );
void Rover_RComm_brake( const i_t );
void Rover_RComm_incrementPower( const i_t );
void Rover_RComm_pollLeaderDistance( void );
void Rover_RComm_pollLeaderGPS( void );
void Rover_RComm_pollRoverCompass( void );
void Rover_RComm_pollRoverGPS( void );
void Rover_RComm_ready( void );
void Rover_RComm_setForwardPower( const i_t );
void Rover_RComm_setLRPower( const i_t, const i_t );
void Rover_RComm__Location_leaderDistance( const r_t );
void Rover_RComm__Location_leaderGPS( const r_t, const r_t );
void Rover_RComm__Location_roverCompass( const r_t );
void Rover_RComm__Location_roverGPS( const r_t, const r_t );

#ifdef	__cplusplus
}
#endif
#endif  /* ROVER_H */
