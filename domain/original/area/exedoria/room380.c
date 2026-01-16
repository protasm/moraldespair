inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Gravel Cross";
  long_desc = "Gravel paths meet in a small clearing of trampled stone. One branch is almost\nlost beneath grass.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room379", "west",
    "domain/original/area/exedoria/room382", "southeast",
    "domain/original/area/exedoria/room381", "north",
  });
}
