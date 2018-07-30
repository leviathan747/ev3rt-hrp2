
/*----------------------------------------------------------------------------
 * File:  EV3TCH_bridge.h
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  EV3TouchSensor (EV3TCH)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef EV3TCH_BRIDGE_H
#define EV3TCH_BRIDGE_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
bool EV3TCH_is_pressed( void );
void EV3TCH_Initialize( void );

#ifdef	__cplusplus
}
#endif
#endif   /* EV3TCH_BRIDGE_H */
