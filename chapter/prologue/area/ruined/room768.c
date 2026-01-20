inherit "room/room";

void create() {
  ::create();

  short_desc = "Gray Court";
  long_desc = "Gray dust coats the paving, and fragments of plaster lie in soft ridges. A broad, straight run of stones implies an old processional path through the ward.";
  dest_dir = ([
    "southwest":"/chapter/prologue/area/ruined/room766",
    "west":"/chapter/prologue/area/ruined/room767",
    "east":"/chapter/prologue/area/ruined/room769",
    "south":"/chapter/prologue/area/ruined/room765",
  ]);

  set_light(1);
}
