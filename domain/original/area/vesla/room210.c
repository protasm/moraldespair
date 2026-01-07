inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken East Riverside Street";
    long_desc = "The roadway along the river is split and sagging, choked with rubble. The embankment is broken, a scar of blistered stone and claw-scraped concrete.\n";
    dest_dir = ({
        "domain/original/area/vesla/room209", "west",
        "domain/original/area/vesla/room211", "east",
        "domain/original/area/vesla/room394", "north",
    });
}

void init() {
    ::init();
    add_action("block_structure", "north");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
