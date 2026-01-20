inherit "room/room";

void create() {
  ::create();

    short_desc = "Shuttered Front";
    long_desc = "A narrow storefront opens to a room of bare shelves and a sagging counter. Dust heaps in the corners, and a faded sign fragment clings to the lintel.";
    dest_dir = ([
      "north":"/chapter/prologue/area/ruined/room191",
    ]);

  set_light(1);
}

