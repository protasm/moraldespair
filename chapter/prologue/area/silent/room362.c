inherit "room/room";

void create() {
  ::create();

  short_desc = "Cobble Hall";
  long_desc = "A cobbled corridor runs straight beneath a low ceiling. Water has darkened the\nstones near the edges.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room356", "south",
    "chapter/prologue/area/silent/room363", "east",
    "chapter/prologue/area/silent/room364", "north",
  });

  set_light(1);
}
