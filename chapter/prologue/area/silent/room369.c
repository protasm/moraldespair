inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Silent Board";
  long_desc = "A weathered board stands against the wall, its notices long since torn away.\nRusted nails hold scraps of curled parchment.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room290",
  ]);

  set_light(1);
}
