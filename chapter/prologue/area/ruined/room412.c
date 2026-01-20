inherit "room/room";

void create() {
  ::create();

  short_desc = "Cinder Bay";
  long_desc = "Cold ash and rusted tools lie scattered across a cracked stone floor. A collapsed bellows and a soot-blackened hearth hint at heat that has not lived here for centuries.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room160",
    "south":"/chapter/prologue/area/ruined/room124",
  ]);

  set_light(1);
}
