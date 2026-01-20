inherit "room/room";

void create() {
  ::create();

    short_desc = "Main Wall Crossing";
    long_desc = "The crossing is wide and empty, marked by worn paving and shallow ruts. A broken curb rings the corner where the streets meet.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room167", "south",
        "chapter/prologue/area/ruined/room793", "west",
        "chapter/prologue/area/ruined/room170", "east",
        "chapter/prologue/area/ruined/room169", "north",
    });

  set_light(1);
}

