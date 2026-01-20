inherit "room/room";

void create() {
  ::create();

  short_desc = "Soot Cut";
  long_desc = "Soot-blackened stone closes in here, and the air is still and stale. A broken lintel and splintered frame imply a long-removed gate.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room795", "south",
    "chapter/prologue/area/ruined/room798", "north",
  });

  set_light(1);
}
