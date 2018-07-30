/*----------------------------------------------------------------------------
 * File:  Navigation.h
 *
 * UML Component (Module) Declaration (Operations and Signals)
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef NAVIGATION_H
#define NAVIGATION_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
void Navigation_CTL_brake( const i_t );
void Navigation_CTL_incrementPower( const i_t );
void Navigation_CTL_pollLeaderDistance( void );
void Navigation_CTL_pollLeaderGPS( void );
void Navigation_CTL_pollRoverCompass( void );
void Navigation_CTL_pollRoverGPS( void );
void Navigation_CTL_ready( void );
void Navigation_CTL_setForwardPower( const i_t );
void Navigation_CTL_setLRPower( const i_t, const i_t );
void Navigation_Navigation_leaderDistance( const r_t );
void Navigation_Navigation_leaderGPS( const r_t, const r_t );
void Navigation_Navigation_roverCompass( const r_t );
void Navigation_Navigation_roverGPS( const r_t, const r_t );

#ifdef	__cplusplus
}
#endif
#endif  /* NAVIGATION_H */
