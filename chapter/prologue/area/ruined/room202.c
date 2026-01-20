inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Way";
  long_desc = "The paving narrows here, uneven and chipped, with damp dust clotted along the edges. Empty brackets jut from the masonry overhead, their purpose lost to the quiet.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room203", "west",
    "chapter/prologue/area/ruined/room201", "east",
    "chapter/prologue/area/ruined/room844", "south",
  });
}
