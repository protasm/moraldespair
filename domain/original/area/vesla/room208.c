inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken East Riverside Street";
    long_desc = "The roadway along the river is split and sagging, choked with rubble. The embankment is broken, a scar of blistered stone and claw-scraped concrete.\n";
    dest_dir = ({
        "domain/original/area/vesla/room207", "west",
        "domain/original/area/vesla/room209", "east",
        "domain/original/area/vesla/room396", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "north");
}

int block_exit() {
    write("A long-collapsed structure leaves only rubble there.\n");
    return 1;
}
