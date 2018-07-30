
/*----------------------------------------------------------------------------
 * File:  EV3COL_bridge.h
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  EV3ColorSensor (EV3COL)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef EV3COL_BRIDGE_H
#define EV3COL_BRIDGE_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
colorid_t EV3COL_get_color( void );
i_t EV3COL_get_reflect( void );
i_t EV3COL_get_ambient( void );
void EV3COL_Initialize( void );
void EV3COL_get_rgb_raw( i_t *, i_t *, i_t * );

#ifdef	__cplusplus
}
#endif
#endif   /* EV3COL_BRIDGE_H */
