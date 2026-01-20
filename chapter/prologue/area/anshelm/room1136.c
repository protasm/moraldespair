inherit "room/room";

void create() {
  ::create();

  short_desc = "Guard Stair";
  long_desc =
    "A tight stairwell spirals upward through the west tower, its steps worn into\n"
    "shallow cups. The air carries the scent of damp stone and old ash.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1135", "down",
    "chapter/prologue/area/anshelm/room1137", "up",
  });

  set_light(1);
}
