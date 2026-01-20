inherit "room/room";

void create() {
  ::create();

  short_desc = "Hollow Hall";
  long_desc = "A wide hall yawns under sagging beams, silent and ruined. Dust, mildew, and rot swallow splintered crates, hinting at bulk storage long abandoned.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room198",
  ]);

  set_light(1);
}
