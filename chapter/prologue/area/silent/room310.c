inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Narrow Lane";
  long_desc = "The lane runs straight between close walls streaked with damp. A thin line of\ngrass follows the center.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room355",
    "south":"/chapter/prologue/area/silent/room311",
    "north":"/chapter/prologue/area/silent/room309",
  ]);

  set_light(1);
}
