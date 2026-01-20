inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Stall";
  long_desc = "An empty shell of a room stands with a cracked lintel and dusted floor. Rotted beams and a few iron brackets suggest a trade space that never returned.";
  dest_dir = ([
    "north":"/chapter/prologue/area/ruined/room795",
  ]);

  set_light(1);
}
