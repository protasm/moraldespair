inherit "room/room";

void create() {
  ::create();

  short_desc = "Middle Steps";
  long_desc = "The stairwell turns here, crowded by damp stone and a fractured landing. Dust cakes the treads, and a broken sconce hints at night watches that ended long ago.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room762", "southwest",
    "chapter/prologue/area/ruined/room760", "down",
    "chapter/prologue/area/ruined/room763", "up",
  });

  set_light(1);
}
