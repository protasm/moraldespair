inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Wood Hall";
  long_desc = "A hallway lined with wooden beams runs between stone walls. The boards are\nwarped and dark with age.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room913",
    "west":"/chapter/prologue/area/silent/room909",
  ]);

  set_light(1);
}
