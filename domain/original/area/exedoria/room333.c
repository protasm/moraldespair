inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Threshold";
  long_desc = "Wide steps lead up to a carved facade streaked with rain. The doorway stands\nopen, its lintel chipped and scarred.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room317", "south",
    "domain/original/area/exedoria/room920", "north",
  });
}
