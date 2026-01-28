inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Quiet Walk";
  long_desc = "The path runs beside a low wall, its capstones cracked. Weeds crowd the base\nwhere soil has risen.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room390",
    "west":"/chapter/prologue/area/silent/room388",
  ]);

  set_light(1);
}
