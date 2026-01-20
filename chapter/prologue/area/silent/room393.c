inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Tower Door";
  long_desc = "The base of a watchtower opens into shadow beneath a cracked arch. Old arrows\nand stones lie scattered outside.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room305", "south",
  });
}
