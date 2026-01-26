inherit "/chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "River Crossing";
    long_desc = "The crossing is a scatter of worn stones, their edges smoothed by time. The two ways meet in silence, framed by damp, crumbling walls.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room/room211",
      "north":"/chapter/prologue/area/ruined/room/room213",
    ]);

}
