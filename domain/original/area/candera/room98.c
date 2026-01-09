inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Faded Corridor";
    long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened\npatches run along the base of the walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room107", "north",
        "domain/original/area/candera/room99", "south",
        "domain/original/area/candera/room1000", "east",
        "domain/original/area/candera/room97", "west",
    });
}

void init() {
    ::init();
    add_action("block_exit", "east");
}

int block_exit() {
    write("The way is blocked by a wall of broken stone.\n");
    return 1;
}
