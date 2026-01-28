inherit "/room/room";

void create() {
  ::create();

  short_desc = "Stair Base";
  long_desc =
    "The base of the eastern stairwell is ringed with fallen tiles. The doorway to\n"
    "the yard stands doorless and warped.\n";
  dest_dir = ([
    "up" : "/chapter/prologue/area/refuge/room1148",
  ]);

  set_light(1);
}
