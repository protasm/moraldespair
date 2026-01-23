inherit "room/room";

void create() {
  ::create();

  short_desc = "West Stair";
  long_desc =
    "A steep stair climbs the western spire, the inner wall scarred by old tool\n"
    "marks. Loose rubble gathers in the corners.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1138",
    "up" : "/chapter/prologue/area/refuge/room1140",
  ]);

  set_light(1);
}
