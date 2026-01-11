inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Main Road";
    long_desc = "The roadway dips slightly, holding a thin skin of damp grit. A sagging doorway\n"
                + "yawns nearby, black with soot.\n";
    dest_dir = ({
        "domain/original/area/vesla/room154", "south",
        "domain/original/area/vesla/room423", "west",
        "domain/original/area/vesla/room422", "east",
        "domain/original/area/vesla/room156", "north",
    });
}

