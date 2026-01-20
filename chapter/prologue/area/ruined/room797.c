inherit "room/room";

void create() {
  ::create();

  short_desc = "Soot Cut";
  long_desc = "Soot-blackened stone closes in here, and the air is still and stale. A broken lintel and splintered frame imply a long-removed gate.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room795",
    "north":"/chapter/prologue/area/ruined/room798",
  ]);

  set_light(1);
}
