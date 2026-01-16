inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Inner Gate";
  long_desc =
    "A second gate rises ahead, its guardwalk broken and open to the sky. Weed-\n"
    "choked steps lead through the arch.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room241", "south",
    "domain/original/area/anshelm/room243", "north",
  });
}
