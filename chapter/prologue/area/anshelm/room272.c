inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruin Lot";
  long_desc =
    "A pit of rubble and half-set stone marks an abandoned build. Weeds knot around\n"
    "a snapped beam.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room271",
  ]);

  set_light(1);
}
