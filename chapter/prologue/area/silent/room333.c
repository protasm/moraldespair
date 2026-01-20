inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Threshold";
  long_desc = "Wide steps lead up to a carved facade streaked with rain. The doorway stands\nopen, its lintel chipped and scarred.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room317", "south",
    "chapter/prologue/area/silent/room920", "north",
  });
}
