inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Walk";
  long_desc = "The path runs beside a low wall, its capstones cracked. Weeds crowd the base\nwhere soil has risen.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room390", "east",
    "domain/original/area/exedoria/room388", "west",
  });
}
