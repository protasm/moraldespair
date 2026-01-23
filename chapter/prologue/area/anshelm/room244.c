inherit "room/room";

void create() {
  ::create();

  short_desc = "Lane Crossing";
  long_desc =
    "A side lane cuts west toward narrower houses. The corner stones are chipped\n"
    "and slick with lichen.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/anshelm/room245",
    "east" : "/chapter/prologue/area/anshelm/room250",
    "south" : "/chapter/prologue/area/anshelm/room243",
  ]);

  set_light(1);
}
