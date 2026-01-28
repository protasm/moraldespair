inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Low Quarters";
  long_desc = "A low-ceilinged room is divided into narrow cubbies. The partitions are warped\nand splintered.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room915",
  ]);

  set_light(1);
}
