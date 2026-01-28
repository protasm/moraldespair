inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Sealed Hall";
  long_desc = "A heavy door and shuttered windows mark a hall that was once important. The\nsign above the entrance hangs broken and unreadable.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room304",
    "north":"/chapter/prologue/area/silent/room287",
  ]);

  set_light(1);
}
