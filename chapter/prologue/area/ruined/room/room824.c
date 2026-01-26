inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Shuttered House";
  long_desc = "Heavy curtains hang in strips, their fabric stiff with dust and mildew. Low couches have collapsed into rot, and a faint sweetness lingers where perfume once clung to the air.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room/room158",
    "up":"/chapter/prologue/area/ruined/room/room825",
  ]);

}
