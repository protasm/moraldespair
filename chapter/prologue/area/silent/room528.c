inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "The path is straight and formal, though its stones have shifted. Silent\nfacades rise on both sides.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room896", "south",
    "chapter/prologue/area/silent/room894", "east",
    "chapter/prologue/area/silent/room527", "north",
  });

  set_light(1);
}
