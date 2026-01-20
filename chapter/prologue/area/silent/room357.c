inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cobble Hall";
  long_desc = "Round cobbles form the hall floor, slick with age. The walls narrow as the\ncorridor stretches on.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room358", "south",
    "chapter/prologue/area/silent/room360", "east",
    "chapter/prologue/area/silent/room356", "north",
  });
}
