inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Somber Junction";
  long_desc = "A wider crossing opens where the paving is deeply scored by cart ruts and rain. The basalt is cracked into plates, and iron rings lie rusted into the stones.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room141",
    "east":"/chapter/prologue/area/ruined/room/room204",
    "north":"/chapter/prologue/area/ruined/room/room139",
  ]);

}

