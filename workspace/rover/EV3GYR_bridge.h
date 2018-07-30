
/*----------------------------------------------------------------------------
 * File:  EV3GYR_bridge.h
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  EV3GyroSensor (EV3GYR)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef EV3GYR_BRIDGE_H
#define EV3GYR_BRIDGE_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
i_t EV3GYR_get_angle( void );
i_t EV3GYR_get_rate( void );
void EV3GYR_reset( void );
void EV3GYR_Initialize( void );

#ifdef	__cplusplus
}
#endif
#endif   /* EV3GYR_BRIDGE_H */
