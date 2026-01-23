inherit "room/room";

void create() {
  ::create();


  short_desc = "Ocean before Beachhead";
  long_desc = "White foam churns over a fractured shoreline where the ocean meets the\n" +
    "land. To the north, a desolate beachhead stretches toward the interior of\n" +
    "a silent island. A small, waterlogged boat drifts aimlessly in the surf,\n" +
    "its wood bleached white by years of salt and sun.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room606",
    "vesla" : "/chapter/prologue/area/ruined/portal",
  ]);

  set_light(1);
}
