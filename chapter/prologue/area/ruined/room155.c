inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Road";
    long_desc = "The roadway dips slightly, holding a thin skin of damp grit. A sagging doorway yawns nearby, black with soot.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room154", "south",
        "chapter/prologue/area/ruined/room423", "west",
        "chapter/prologue/area/ruined/room422", "east",
        "chapter/prologue/area/ruined/room156", "north",
    });
}


