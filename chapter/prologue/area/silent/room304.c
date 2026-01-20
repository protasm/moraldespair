inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Road";
  long_desc = "The roadbed dips where the ground has settled. Broken walls crowd close on\neither side.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room305", "west",
    "chapter/prologue/area/silent/room303", "east",
    "chapter/prologue/area/silent/room330", "north",
  });

  set_light(1);
}
