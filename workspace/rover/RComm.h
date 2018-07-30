/*----------------------------------------------------------------------------
 * File:  RComm.h
 *
 * UML Component (Module) Declaration (Operations and Signals)
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef RCOMM_H
#define RCOMM_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
void RComm_RComm_brake( const i_t );
void RComm_RComm_incrementPower( const i_t );
void RComm_RComm_pollLeaderDistance( void );
void RComm_RComm_pollLeaderGPS( void );
void RComm_RComm_pollRoverCompass( void );
void RComm_RComm_pollRoverGPS( void );
void RComm_RComm_ready( void );
void RComm_RComm_setForwardPower( const i_t );
void RComm_RComm_setLRPower( const i_t, const i_t );
void RComm_Location_leaderDistance( const r_t );
void RComm_Location_leaderGPS( const r_t, const r_t );
void RComm_Location_roverCompass( const r_t );
void RComm_Location_roverGPS( const r_t, const r_t );

#ifdef	__cplusplus
}
#endif
#endif  /* RCOMM_H */
