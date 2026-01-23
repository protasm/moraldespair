inherit "room/room";

void create() {
  ::create();

  short_desc = "Outer Stair";
  long_desc =
    "The stairwell winds downward in the west wall, slick with damp. Chips of\n"
    "limestone litter the treads.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1135",
    "up" : "/chapter/prologue/area/refuge/room1162",
  ]);

  set_light(1);
}
