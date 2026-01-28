inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Westroad Drift";
  long_desc = "Windblown grit has gathered in thin drifts along the road. The stonework is stained and pitted, and a few twisted iron bands cling to the wall.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room132",
    "east":"/chapter/prologue/area/ruined/room/room130",
  ]);

}
