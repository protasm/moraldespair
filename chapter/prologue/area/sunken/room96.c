inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ash-Streaked Crossing";
    long_desc = "A narrow lane bends between broken walls, the ground uneven and gritty. Char marks stripe the walls, and fine ash mixes with grit underfoot.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room977", "north",
        "chapter/prologue/area/sunken/room976", "south",
        "chapter/prologue/area/sunken/room97", "east",
        "chapter/prologue/area/sunken/room95", "west",
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
