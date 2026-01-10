inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "East River Track";
    long_desc = "A shallow rut marks the center line, worn deep before\n"
                + "the silence.\n"
                + "Small piles of gravel gather against the curb.\n";
    dest_dir = ({
        "domain/original/area/vesla/room208", "west",
        "domain/original/area/vesla/room210", "east",
        "domain/original/area/vesla/room395", "north",
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
