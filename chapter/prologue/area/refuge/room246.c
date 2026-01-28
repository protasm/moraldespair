inherit "/room/room";

void create() {
  ::create();

  short_desc = "Shaded Lane";
  long_desc =
    "The street stays in shadow beneath overhanging roofs. Damp plaster flakes from\n"
    "the walls in thin curls.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room247",
    "east" : "/chapter/prologue/area/refuge/room245",
    "south" : "/chapter/prologue/area/refuge/room249",
  ]);

  set_light(1);
}
