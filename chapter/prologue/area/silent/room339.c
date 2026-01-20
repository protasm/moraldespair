inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Bridge";
  long_desc = "The bridge arches over a dry channel, its sides worn smooth. Moss gathers\nalong the parapet where hands once rested.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room340", "east",
    "chapter/prologue/area/silent/room338", "west",
  });
}
