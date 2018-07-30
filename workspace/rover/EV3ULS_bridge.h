
/*----------------------------------------------------------------------------
 * File:  EV3ULS_bridge.h
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  EV3UltrasonicSensor (EV3ULS)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef EV3ULS_BRIDGE_H
#define EV3ULS_BRIDGE_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
i_t EV3ULS_get_distance( void );
bool EV3ULS_is_detected( void );
void EV3ULS_Initialize( void );

#ifdef	__cplusplus
}
#endif
#endif   /* EV3ULS_BRIDGE_H */
