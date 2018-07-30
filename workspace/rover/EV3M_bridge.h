
/*----------------------------------------------------------------------------
 * File:  EV3M_bridge.h
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  EV3Motor (EV3M)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef EV3M_BRIDGE_H
#define EV3M_BRIDGE_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
i_t EV3M_get_count( const device_motor_t );
void EV3M_reset_count( const device_motor_t );
mclm_result_t EV3M_set_power( const device_motor_t, const i_t );
i_t EV3M_get_power( const device_motor_t );
mclm_result_t EV3M_stop( const bool, const device_motor_t );
mclm_result_t EV3M_steer( const i_t, const i_t );
void EV3M_Initialize( void );

#ifdef	__cplusplus
}
#endif
#endif   /* EV3M_BRIDGE_H */
