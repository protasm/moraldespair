inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Lawn";
  long_desc = "A lawn once trimmed is now wild, dotted with shattered stone figures. Moss\ncoats the remaining bases.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room345", "south",
    "domain/original/area/exedoria/room343", "north",
  });
}
