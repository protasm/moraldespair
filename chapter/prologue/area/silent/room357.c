inherit "room/room";

void create() {
  ::create();

  short_desc = "Cobble Hall";
  long_desc = "Round cobbles form the hall floor, slick with age. The walls narrow as the\ncorridor stretches on.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room358", "south",
    "chapter/prologue/area/silent/room360", "east",
    "chapter/prologue/area/silent/room356", "north",
  });

  set_light(1);
}
