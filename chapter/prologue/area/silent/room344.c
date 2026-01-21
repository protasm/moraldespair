inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Lawn";
  long_desc = "A lawn once trimmed is now wild, dotted with shattered stone figures. Moss\ncoats the remaining bases.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room345",
    "north":"/chapter/prologue/area/silent/room343",
  ]);

  set_light(1);
}
