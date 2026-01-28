inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "West Street";
  long_desc = "The street widens slightly here before narrowing into ruins. Broken shutters\nand beams lie along the verge.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room335",
  ]);

  set_light(1);
}
