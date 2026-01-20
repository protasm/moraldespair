inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Watch";
  long_desc = "A squat tower rises above the wall, its stairs broken. The top is open to rain\nand birds.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room920", "down",
    "chapter/prologue/area/silent/room922", "north",
  });

  set_light(1);
}
