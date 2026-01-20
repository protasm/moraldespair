inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Row";
  long_desc = "Tall facades line the street, their balconies empty. Old banners have left\npale marks on the stone.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room313", "west",
    "chapter/prologue/area/silent/room315", "east",
    "chapter/prologue/area/silent/room322", "south",
  });
}
