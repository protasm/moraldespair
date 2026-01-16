inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Way";
  long_desc =
    "The paving narrows here, uneven and chipped, with damp dust clotted along\n"
    "the edges. Empty brackets jut from the masonry overhead, their purpose lost\n"
    "to the quiet.\n";
  dest_dir = ({
    "domain/original/area/vesla/room203", "west",
    "domain/original/area/vesla/room201", "east",
    "domain/original/area/vesla/room844", "south",
  });
}
