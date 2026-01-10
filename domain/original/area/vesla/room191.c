inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scholar's Way";
    long_desc = "Scholar's Way";
    dest_dir = ({
        "domain/original/area/vesla/room742", "south",
        "domain/original/area/vesla/room192", "west",
        "domain/original/area/vesla/room190", "east",
        "domain/original/area/vesla/room743", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "south");
    add_action("block_exit", "north");
}

int block_exit() {
    write("Rubble blocks the way; the structure has long since fallen.\n");
    return 1;
}
