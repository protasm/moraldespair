inherit "room/room";

void create() {
  ::create();

  short_desc = "Tower Gap";
  long_desc = "The gap between the towers narrows here, with soot-dark stone and warped iron bands clinging to the walls. The floor is littered with crumbling mortar and a rot-stained beam that once barred the way.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room754", "south",
    "chapter/prologue/area/ruined/room756", "north",
  });

  set_light(1);
}
