inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Bridge";
  long_desc = "The bridge arches over a dry channel, its sides worn smooth. Moss gathers\nalong the parapet where hands once rested.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room340", "east",
    "domain/original/area/exedoria/room338", "west",
  });
}
