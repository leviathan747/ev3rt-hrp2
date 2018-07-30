/*----------------------------------------------------------------------------
 * File:  EV3M_bridge.c
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  EV3Motor (EV3M)
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
#include "EV3M_bridge.h"
#include "mclm_ev3.h"

static motor_port_t motor_map[DEV_MOTOR_MAX];
static int motor_invert[DEV_MOTOR_MAX];

static int run_flag = 0;

void EV3M_Initialize(void)
{
	
  motor_map[DEV_MOTOR_LEFT] = EV3_PORT_B;
  ev3_motor_config(EV3_PORT_B, LARGE_MOTOR);
  motor_map[DEV_MOTOR_RIGHT] = EV3_PORT_C;
  ev3_motor_config(EV3_PORT_C, LARGE_MOTOR);
	
  motor_invert[DEV_MOTOR_LEFT] = 1;
  motor_invert[DEV_MOTOR_RIGHT] = 1;

	run_flag = 1;
}	

/*
 * Bridge:  get_count
 */
i_t
EV3M_get_count( const  device_motor_t p_motor )
{
	return ev3_motor_get_counts(motor_map[p_motor])* motor_invert[p_motor];

}


/*
 * Bridge:  reset_count
 */
void
EV3M_reset_count( const device_motor_t p_motor )
{
	ev3_motor_reset_counts(motor_map[p_motor]);
}


/*
 * Bridge:  set_power
 */
mclm_result_t
EV3M_set_power( const device_motor_t p_motor, const i_t p_power )
{
	if ( !run_flag ) return  MCLM_RESULT_OK;
	
	if (ev3_motor_set_power(motor_map[p_motor],p_power*motor_invert[p_motor]) != E_OK ) {
		return MCLM_RESULT_ERROR;
	}
	return MCLM_RESULT_OK;

}


/*
 * Bridge:  get_power
 */
i_t
EV3M_get_power( const device_motor_t p_motor )
{
	return ev3_motor_get_power(motor_map[p_motor])*motor_invert[p_motor];
}


/*
 * Bridge:  stop
 */
mclm_result_t
EV3M_stop( const bool p_brake, const device_motor_t p_motor )
{
	if ( ev3_motor_stop(motor_map[p_motor],p_brake) != E_OK ) {
		return MCLM_RESULT_ERROR;
	}
	return MCLM_RESULT_OK;
}


/*
 * Bridge:  steer
 */
mclm_result_t
EV3M_steer( const i_t p_power, const i_t p_ratio )
{
	if ( !run_flag ) return  MCLM_RESULT_OK;

	if ( ev3_motor_steer(motor_map[DEV_MOTOR_LEFT],
			motor_map[DEV_MOTOR_RIGHT],
			p_power*motor_invert[DEV_MOTOR_LEFT],
	p_ratio*motor_invert[DEV_MOTOR_LEFT] ) != E_OK ) {
		return MCLM_RESULT_ERROR;
	}
	return MCLM_RESULT_OK;
}


void EV3M_Shutdown(void)
{
	run_flag = 0;

	int pt;
	for ( pt = 0; pt < TNUM_MOTOR_PORT; pt++ ) {
		if ( ev3_motor_get_type(pt) != E_ID ) {
			ev3_motor_stop(pt,true);
		}
	}
	
	
}

