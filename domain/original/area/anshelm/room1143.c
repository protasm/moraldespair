inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Lounge";
  long_desc =
    "Wide windows face the street, their frames hanging loose and bare. Bits of\n"
    "colored plaster remain on the walls, muted by age.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room236", "east",
    "domain/original/area/anshelm/room1204", "west",
  });
}
