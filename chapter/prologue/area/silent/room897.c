inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Walk";
  long_desc = "A long walk stretches across a quiet quadrangle. The air is still beneath\ntall, weathered walls.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room898", "south",
    "chapter/prologue/area/silent/room896", "north",
  });
}
