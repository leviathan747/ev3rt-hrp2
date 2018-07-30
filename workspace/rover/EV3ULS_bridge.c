/*----------------------------------------------------------------------------
 * File:  EV3ULS_bridge.c
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  EV3UltrasonicSensor (EV3ULS)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ev3api.h"
#include "app.h"

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

#include "Rover_sys_types.h"
#include "EV3ULS_bridge.h"
#include "mclm_ev3.h"

static sensor_port_t port = TNUM_SENSOR_PORT;

void EV3ULS_Initialize(void)
{
	if ( port < TNUM_SENSOR_PORT ) 
		ev3_sensor_config(port,ULTRASONIC_SENSOR);
}


/*
 * Bridge:  get_distance
 */
i_t
EV3ULS_get_distance()
{
	return ev3_ultrasonic_sensor_get_distance(port);

}


/*
 * Bridge:  is_detected
 */
bool
EV3ULS_is_detected()
{
	return ev3_ultrasonic_sensor_listen(port);

}


