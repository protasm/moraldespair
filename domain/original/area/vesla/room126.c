inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cindered End of a Ruined Street";
    long_desc = "The ruined street ends in a jumble of shattered stones and "
        + "charred stumps. The road lies broken and dead, gouged by "
        + "something enormous.\n";
    dest_dir = ({
        "domain/original/area/vesla/room880", "south",
        "domain/original/area/vesla/room127", "west",
        "domain/original/area/vesla/room125", "east",
        "domain/original/area/vesla/room879", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "south");
    add_action("block_exit", "north");
}

int block_exit() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
