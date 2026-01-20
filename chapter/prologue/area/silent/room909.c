inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Grand Foyer";
  long_desc = "A tall foyer rises toward a broken skylight. Bits of colored glass glitter in\nthe dust.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room914", "up",
    "chapter/prologue/area/silent/room911", "west",
    "chapter/prologue/area/silent/room912", "east",
    "chapter/prologue/area/silent/room908", "south",
  });
}
