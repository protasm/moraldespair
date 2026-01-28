inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Narrow Alley";
  long_desc = "This passage is hemmed by close walls and a broken gutter. Thin weeds reach up\nfrom packed dirt.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room326",
    "north":"/chapter/prologue/area/silent/room328",
  ]);

  set_light(1);
}
