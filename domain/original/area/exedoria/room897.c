inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Walk";
  long_desc = "A long walk stretches across a quiet quadrangle. The air is still beneath\ntall, weathered walls.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room898", "south",
    "domain/original/area/exedoria/room896", "north",
  });
}
