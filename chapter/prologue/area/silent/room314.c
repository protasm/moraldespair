inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Row";
  long_desc = "Tall facades line the street, their balconies empty. Old banners have left\npale marks on the stone.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room313",
    "east":"/chapter/prologue/area/silent/room315",
    "south":"/chapter/prologue/area/silent/room322",
  ]);

  set_light(1);
}
