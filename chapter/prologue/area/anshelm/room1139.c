inherit "room/room";

void create() {
  ::create();

  short_desc = "West Stair";
  long_desc =
    "A steep stair climbs the western spire, the inner wall scarred by old tool\n"
    "marks. Loose rubble gathers in the corners.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1138", "down",
    "chapter/prologue/area/anshelm/room1140", "up",
  });

  set_light(1);
}
