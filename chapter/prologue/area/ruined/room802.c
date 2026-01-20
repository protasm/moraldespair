inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Crooked Cut";
  long_desc = "This crooked alley is lined with cracked stone and peeling plaster that smells of old damp. A broken curb and shallow ruts hint at steady foot and cart traffic.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room805", "south",
    "chapter/prologue/area/ruined/room803", "west",
    "chapter/prologue/area/ruined/room799", "east",
    "chapter/prologue/area/ruined/room807", "north",
  });
}
