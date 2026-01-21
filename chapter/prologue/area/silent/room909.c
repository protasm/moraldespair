inherit "room/room";

void create() {
  ::create();

  short_desc = "Grand Foyer";
  long_desc = "A tall foyer rises toward a broken skylight. Bits of colored glass glitter in\nthe dust.\n";
  dest_dir = ([
    "up":"/chapter/prologue/area/silent/room914",
    "west":"/chapter/prologue/area/silent/room911",
    "east":"/chapter/prologue/area/silent/room912",
    "south":"/chapter/prologue/area/silent/room908",
  ]);

  set_light(1);
}
