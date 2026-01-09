inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "ash-streaked crossing";
    long_desc = "A narrow lane bends between broken walls, the ground uneven and gritty. Char marks stripe the walls, and fine ash mixes with grit underfoot.\n";
    dest_dir = ({
        "domain/original/area/candera/room977", "north",
        "domain/original/area/candera/room976", "south",
        "domain/original/area/candera/room97", "east",
        "domain/original/area/candera/room95", "west",
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
