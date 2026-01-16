inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Crumbling Hall";
  long_desc = "A broad civic hall slumps behind a fallen portico. Its doors gape open onto\ndust and broken benches.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room291", "north",
  });
}
