inherit "/room/room";

void create() {
  ::create();

  short_desc = "Silent Taproom";
  long_desc =
    "A low room opens onto the street, its counter broken and bare. Stained glass\n"
    "fragments glimmer in the dust.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room1191",
    "south" : "/chapter/prologue/area/refuge/room1186",
  ]);

  set_light(1);
}
