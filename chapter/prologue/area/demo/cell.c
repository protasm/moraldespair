inherit "/chapter/prologue/std/room";

#include <globals.h>
#include <link.h>

void create() {
  object door;
  mapping def;

  ::create();

  short_desc = "Prison Cell";
  long_desc =
    "Cold stone presses in from every side. Iron bars seal the cell, and a\n"
    "stale smell of damp straw and rust hangs in the air. The only apparent\n"
    "way out lies to the east.\n";

  set_light(1);

  /****************************************************************
   * TEMPORARY TOPOLOGY HACK
   * ----------------------
   * This link definition lives here ONLY temporarily.
   *
   * Assumptions:
   * - Player always starts in this room
   * - Guard room cannot be approached first
   *
   * TODO: Move this to /chapter/prologue/area/demo/topology.c
   ****************************************************************/
  if (!LINK_D->query_link(
        "/chapter/prologue/area/demo/cell",
        "/chapter/prologue/area/demo/guard_room")) {

    door = new("/core/gate_door");
    door->set_name("iron cell door");

    /* Locked on guard-room side (SIDE_B = 1) */
    //door->set_lock_id(1, "iron_key");
    //door->set_locked_state(1, 1);

    //door->set_block_message(0,
      //"You rattle the bars, but the iron door won't budge.");
    //door->set_block_message(1,
      //"The iron door is locked fast from this side.");

    //door->set_base_cost(1);

    //def = ([
    //  "type"  : "/core/link",
    //  "gates" : ({ door }),
    //]);

    //LINK_D->define_link(
    //  "/chapter/prologue/area/demo/cell",
    //  "/chapter/prologue/area/demo/guard_room",
    //  def
    //);
  }

  /*
   * Discover the link normally.
   * This is the correct long-term pattern.
   */
  //add_link("east", LINK_D->get_link(
  //  base_name(this_object()),
  //  "/chapter/prologue/area/demo/guard_room"
  //));
}

