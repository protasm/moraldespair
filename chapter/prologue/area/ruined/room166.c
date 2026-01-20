inherit "room/room";

void create() {
  ::create();

    short_desc = "Darkened Crossing";
    long_desc = "Two streets cross in a square of uneven stone. The corners are piled with broken masonry and grit.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room165",
      "east":"/chapter/prologue/area/ruined/room192",
      "north":"/chapter/prologue/area/ruined/room167",
    ]);

  set_light(1);
}

