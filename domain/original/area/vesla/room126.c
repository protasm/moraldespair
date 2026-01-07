inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cindered End of Park Street";
    long_desc = "Park Street ends in a jumble of shattered stones and charred stumps. The dragons' passage left the road broken and dead.\n";
    dest_dir = ({
        "domain/original/area/vesla/room880", "south",
        "domain/original/area/vesla/room127", "west",
        "domain/original/area/vesla/room125", "east",
        "domain/original/area/vesla/room879", "north",
    });
}

void init() {
    add_action("block_structure", "south");
    add_action("block_structure", "north");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
