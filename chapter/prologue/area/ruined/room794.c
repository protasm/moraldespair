inherit "room/room";

void create() {
  ::create();

  short_desc = "Grate Shed";
  long_desc = "A low shed sags over a grated stone lip, its boards soft with rot. Mildew and silt stain the edges, hinting at a passage once kept clear below.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room792",
  ]);

  set_light(1);
}
