inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Echo Court";
  long_desc = "The court here is narrower, hemmed by rough walls and roofless alcoves. A rusted bracket and a shallow socket in the stone hint at a former lantern line.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room/room768",
    "southeast":"/chapter/prologue/area/ruined/room/room765",
    "south":"/chapter/prologue/area/ruined/room/room766",
  ]);

}
