inherit "room/room";

void create() {
  ::create();

  short_desc = "Outer Stair";
  long_desc =
    "The stairwell winds downward in the west wall, slick with damp. Chips of\n"
    "limestone litter the treads.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1135", "down",
    "chapter/prologue/area/anshelm/room1162", "up",
  });

  set_light(1);
}
