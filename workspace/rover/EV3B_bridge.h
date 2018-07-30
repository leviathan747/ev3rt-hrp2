

/*----------------------------------------------------------------------------
 * File:  EV3B_bridge.h
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  EV3Body (EV3B)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef EV3B_BRIDGE_H
#define EV3B_BRIDGE_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "Rover_sys_types.h"
i_t EV3B_get_battery_voltage( void );
i_t EV3B_get_battery_current( void );
bool EV3B_is_button_pressed( const button_t );
void EV3B_led_set_color( const ledcolor_t );
void EV3B_speaker_play_file( const i_t, c_t[ESCHER_SYS_MAX_STRING_LEN] );
void EV3B_speaker_play_tone( const i_t, const i_t );
void EV3B_speaker_set_volume( const i_t );
void EV3B_speaker_stop( void );
bool EV3B_bluetooth_is_connected( void );
mclm_result_t EV3B_image_load( c_t[ESCHER_SYS_MAX_STRING_LEN] );
void EV3B_draw_image( c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t, const i_t );
void EV3B_lcd_draw_line( const i_t, const i_t, const i_t, const i_t );
void EV3B_lcd_draw_string( c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t, const i_t );
void EV3B_lcd_fill_rect( const lcdcolor_t, const i_t, const i_t, const i_t, const i_t );
void EV3B_lcd_set_font( const lcdfont_t );
void EV3B_Initialize( void );
c_t * EV3B_int_to_str( c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t );
void EV3B_bluetooth_write( c_t[ESCHER_SYS_MAX_STRING_LEN] );

#ifdef	__cplusplus
}
#endif
#endif   /* EV3B_BRIDGE_H */
