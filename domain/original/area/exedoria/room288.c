inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Broken stones show where wheels once cut a track through the city. Old gutter\nstones run broken and half buried at the sides.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room368", "south",
    "domain/original/area/exedoria/room287", "west",
    "domain/original/area/exedoria/room289", "east",
    "domain/original/area/exedoria/room367", "north",
  });
}
