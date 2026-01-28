inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Gravel Path";
  long_desc = "Loose gravel crunches along a narrow path. The ground beside it is soft with\nmoss.\n";
  dest_dir = ([
    "southeast":"/chapter/prologue/area/silent/room604",
    "northeast":"/chapter/prologue/area/silent/room908",
  ]);

  set_light(1);
}
