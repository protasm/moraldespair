inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Common Hall";
  long_desc = "Long tables stand in a wide hall, their surfaces split and gray. A cold hearth\nsits at the far end.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room894", "north",
  });
}
