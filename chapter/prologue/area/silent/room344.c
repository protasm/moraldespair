inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Lawn";
  long_desc = "A lawn once trimmed is now wild, dotted with shattered stone figures. Moss\ncoats the remaining bases.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room345", "south",
    "chapter/prologue/area/silent/room343", "north",
  });

  set_light(1);
}
