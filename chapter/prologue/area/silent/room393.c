inherit "room/room";

void create() {
  ::create();

  short_desc = "Tower Door";
  long_desc = "The base of a watchtower opens into shadow beneath a cracked arch. Old arrows\nand stones lie scattered outside.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room305",
  ]);

  set_light(1);
}
