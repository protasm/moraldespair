inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Middle Steps";
  long_desc = "The stairwell turns here, crowded by damp stone and a fractured landing. Dust cakes the treads, and a broken sconce hints at night watches that ended long ago.";
  dest_dir = ([
    "southwest":"/chapter/prologue/area/ruined/room/room762",
    "down":"/chapter/prologue/area/ruined/room/room760",
    "up":"/chapter/prologue/area/ruined/room/room763",
  ]);

}
