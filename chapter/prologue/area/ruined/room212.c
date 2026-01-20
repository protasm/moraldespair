inherit "room/room";

void create() {
  ::create();

    short_desc = "River Crossing";
    long_desc = "The crossing is a scatter of worn stones, their edges smoothed by time. The two ways meet in silence, framed by damp, crumbling walls.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room211", "west",
        "chapter/prologue/area/ruined/room213", "north",
    });

  set_light(1);
}
