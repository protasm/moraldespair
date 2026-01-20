inherit "room/room";

void create() {
  ::create();

  short_desc = "Crooked Cut";
  long_desc = "This crooked alley is lined with cracked stone and peeling plaster that smells of old damp. A broken curb and shallow ruts hint at steady foot and cart traffic.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room805",
    "west":"/chapter/prologue/area/ruined/room803",
    "east":"/chapter/prologue/area/ruined/room799",
    "north":"/chapter/prologue/area/ruined/room807",
  ]);

  set_light(1);
}
