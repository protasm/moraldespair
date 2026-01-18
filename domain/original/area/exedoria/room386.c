inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Black Gate";
  long_desc = "A tall gate of dark iron stands between two cracked pillars. The metal is\npitted and flecked with rust.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room384", "northwest",
    "domain/original/area/exedoria/room387", "southeast",
  });
}
