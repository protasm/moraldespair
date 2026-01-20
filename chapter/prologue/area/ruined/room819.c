inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Plot";
  long_desc = "Low foundations break through the weeds, and a warped signpost lies in the dust. Rain has pooled in shallow pits, leaving rot and mildew along the stone.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room152", "east",
  });
}
