inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Bitter Parlor";
  long_desc = "A small parlor sits empty, its counters broken and its shelves collapsed into dusty piles. A darkened hearth and stained ledges suggest warm cups and quiet trade now gone cold.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room157", "east",
  });
}
