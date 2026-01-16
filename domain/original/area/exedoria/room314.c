inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Row";
  long_desc = "Tall facades line the street, their balconies empty. Old banners have left\npale marks on the stone.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room313", "west",
    "domain/original/area/exedoria/room315", "east",
    "domain/original/area/exedoria/room322", "south",
  });
}
