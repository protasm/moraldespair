inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Western Gate";
  long_desc = "The western gate has collapsed into a heap of stone and splintered wood. Rusted fittings lie half buried, and the blocked passage holds a deep, unmoving quiet.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room/room133",
    "exit":"/chapter/prologue/area/roadway/room12",
  ]);
}
