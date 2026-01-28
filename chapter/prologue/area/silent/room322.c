inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Check";
  long_desc = "A narrow archway divides the street, flanked by low guard niches. The stone\nbears faint carvings worn flat by time.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room314",
  ]);

  set_light(1);
}
