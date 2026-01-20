inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Passage";
    long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire- blackened patches run along the base of the walls.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room82", "west",
        "chapter/prologue/area/sunken/room1099", "down",
    });
}

void init() {
    ::init();
    add_action("block_exit", "down");
}

int block_exit() {
    write("The way is blocked by a wall of broken stone.\n");
    return 1;
}
