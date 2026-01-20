inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Taproom";
  long_desc =
    "A low room opens onto the street, its counter broken and bare. Stained glass\n"
    "fragments glimmer in the dust.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1191", "west",
    "chapter/prologue/area/anshelm/room1186", "south",
  });

  set_light(1);
}
