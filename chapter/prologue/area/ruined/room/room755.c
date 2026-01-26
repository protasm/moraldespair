inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Tower Gap";
  long_desc = "The gap between the towers narrows here, with soot-dark stone and warped iron bands clinging to the walls. The floor is littered with crumbling mortar and a rot-stained beam that once barred the way.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room754",
    "north":"/chapter/prologue/area/ruined/room/room756",
  ]);

}
