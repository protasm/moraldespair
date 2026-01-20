inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Lounge";
  long_desc =
    "Wide windows face the street, their frames hanging loose and bare. Bits of\n"
    "colored plaster remain on the walls, muted by age.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room236", "east",
    "chapter/prologue/area/anshelm/room1204", "west",
  });

  set_light(1);
}
