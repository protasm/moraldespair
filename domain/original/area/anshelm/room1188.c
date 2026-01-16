inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Avenue";
  long_desc =
    "The avenue is paved in broad stones worn smooth by time. A row of bent iron\n"
    "lamps leans over the gutter.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1189", "east",
    "domain/original/area/anshelm/room1187", "west",
  });
}
