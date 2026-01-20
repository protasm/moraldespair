inherit "room/room";

void create() {
  ::create();

    short_desc = "Rotted Racks";
    long_desc = "Warped wooden frames cling to the walls, their joints loose and splintered. Cobwebs gather in the corners, and a sour dampness hangs over the floor.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room748",
    ]);

  set_light(1);
}

