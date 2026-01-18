inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Silence";
  long_desc = "The road narrows into a quiet channel of stone and dust. A collapsed lintel lies across one wall, and the space beyond it is dark and empty.";
  dest_dir = ({
    "domain/original/area/vesla/room131", "west",
    "domain/original/area/vesla/room129", "east",
    "domain/original/area/vesla/room420", "south",
  });
}
