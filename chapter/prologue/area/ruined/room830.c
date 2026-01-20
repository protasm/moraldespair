inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cold Oven";
  long_desc = "The room is thick with old flour dust and collapsed racks, the stone floor sticky with mildew. A soot-dark oven mouth gapes in the back wall, long since cold.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room157", "west",
  });
}
