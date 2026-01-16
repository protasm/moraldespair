inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Guard Stair";
  long_desc =
    "A tight stairwell spirals upward through the west tower, its steps worn into\n"
    "shallow cups. The air carries the scent of damp stone and old ash.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1135", "down",
    "domain/original/area/anshelm/room1137", "up",
  });
}
