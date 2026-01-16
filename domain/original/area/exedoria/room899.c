inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Walk";
  long_desc = "A formal walkway continues between shuttered halls. Only wind and birds move\namong the stones.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room902", "south",
    "domain/original/area/exedoria/room900", "east",
    "domain/original/area/exedoria/room898", "north",
  });
}
