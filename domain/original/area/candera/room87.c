inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bleached Bend";
    long_desc = "Broken steps climb to a terrace of shattered stone, then fall away. Char marks stripe the walls, and fine ash mixes with grit underfoot.";
    dest_dir = ({
        "domain/original/area/candera/room88", "north",
        "domain/original/area/candera/room86", "south",
        "domain/original/area/candera/room1082", "west",
    });
}

void init() {
    ::init();
    add_action("block_exit", "west");
}

int block_exit() {
    write("The way is blocked by a wall of broken stone.\n");
    return 1;
}
