inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scarred Hollow";
    long_desc = "The route skirts a collapsed chamber, its edge cut clean by fire. Hollow window\nframes stare out, their ledges buried in dust.\n";
    dest_dir = ({
        "domain/original/area/candera/room1018", "north",
        "domain/original/area/candera/room1019", "south",
        "domain/original/area/candera/room73", "east",
        "domain/original/area/candera/room75", "west",
    });
}

void init() {
    ::init();
    add_action("block_exit", "north");
}

int block_exit() {
    write("The way is blocked by a wall of broken stone.\n");
    return 1;
}
