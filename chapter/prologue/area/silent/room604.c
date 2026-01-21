inherit "room/room";

void create() {
  ::create();

  short_desc = "Private Yard";
  long_desc = "A low wall encloses a yard gone to weeds. A warped signpost leans among the\ngrass.\n";
  dest_dir = ([
    "northeast":"/chapter/prologue/area/silent/room907",
    "northwest":"/chapter/prologue/area/silent/room910",
    "south":"/chapter/prologue/area/silent/room338",
  ]);

  set_light(1);
}
