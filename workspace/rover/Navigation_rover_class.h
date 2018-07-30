
/*----------------------------------------------------------------------------
 * File:  Navigation_rover_class.h
 *
 * Class:       rover  (rover)
 * Component:   Navigation
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef NAVIGATION_ROVER_CLASS_H
#define NAVIGATION_ROVER_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   rover  (rover)
 */
struct Navigation_rover {

  /* application analysis class attributes */
  Rover_sdt_position curPosition;  /* - curPosition */
  Rover_sdt_position prevPosition;  /* - prevPosition */
  Rover_sdt_position oldPosition;  /* - oldPosition */
  /* relationship storage */
  void * R1_subtype;
  Escher_ClassNumber_t R1_object_id;
};


/* Accessors to rover[R1] subtypes */
#define Navigation_leader_R1_From_rover( rover ) \
   ( (((rover)->R1_object_id) == Navigation_leader_CLASS_NUMBER) ? \
     ((Navigation_leader *)((rover)->R1_subtype)) : (0) )
#define Navigation_follower_R1_From_rover( rover ) \
   ( (((rover)->R1_object_id) == Navigation_follower_CLASS_NUMBER) ? \
     ((Navigation_follower *)((rover)->R1_subtype)) : (0) )


#define Navigation_rover_MAX_EXTENT_SIZE 200
extern Escher_Extent_t pG_Navigation_rover_extent;

#ifdef	__cplusplus
}
#endif

#endif  /* NAVIGATION_ROVER_CLASS_H */
