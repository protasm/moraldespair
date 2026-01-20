inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Oven";
  long_desc = "The room is thick with old flour dust and collapsed racks, the stone floor sticky with mildew. A soot-dark oven mouth gapes in the back wall, long since cold.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room157",
  ]);

  set_light(1);
}
