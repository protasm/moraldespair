inherit "/room/room";

void create() {
  ::create();

  short_desc = "Guard Stair";
  long_desc =
    "A tight stairwell spirals upward through the west tower, its steps worn into\n"
    "shallow cups. The air carries the scent of damp stone and old ash.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1135",
    "up" : "/chapter/prologue/area/refuge/room1137",
  ]);

  set_light(1);
}
