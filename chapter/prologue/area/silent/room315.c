inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Row";
  long_desc = "A formal row of buildings rises in matched stone. Windows stare out as dark,\nbroken squares.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room320", "south",
    "chapter/prologue/area/silent/room314", "west",
    "chapter/prologue/area/silent/room316", "east",
    "chapter/prologue/area/silent/room321", "north",
  });
}
