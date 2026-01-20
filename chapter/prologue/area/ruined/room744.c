inherit "room/room";

void create() {
  ::create();

    short_desc = "Bare Plot";
    long_desc = "A broad patch of bare earth interrupts the street, rimmed by broken foundations. Splintered posts and sunken stones hint at a lost structure beneath the weeds.";
    dest_dir = ([
      "north":"/chapter/prologue/area/ruined/room192",
    ]);

  set_light(1);
}

