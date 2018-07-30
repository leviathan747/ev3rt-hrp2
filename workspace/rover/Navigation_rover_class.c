/*----------------------------------------------------------------------------
 * File:  Navigation_rover_class.c
 *
 * Class:       rover  (rover)
 * Component:   Navigation
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "Rover_sys_types.h"
#include "EV3B_bridge.h"
#include "EV3COL_bridge.h"
#include "EV3GYR_bridge.h"
#include "EV3M_bridge.h"
#include "EV3TCH_bridge.h"
#include "EV3ULS_bridge.h"
#include "LOG_bridge.h"
#include "TIM_bridge.h"
#include "Navigation_classes.h"


/* Accessors to rover[R1] subtypes */

/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s Navigation_rover_container[ Navigation_rover_MAX_EXTENT_SIZE ];
static Navigation_rover Navigation_rover_instances[ Navigation_rover_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_Navigation_rover_extent = {
  {0}, {0}, &Navigation_rover_container[ 0 ],
  (Escher_iHandle_t) &Navigation_rover_instances,
  sizeof( Navigation_rover ), 0, Navigation_rover_MAX_EXTENT_SIZE
  };

