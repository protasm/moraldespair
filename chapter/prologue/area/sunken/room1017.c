inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Strewn Walk";
    long_desc = "An open stretch of hard-packed grit marks a crossing of several lines. Splintered tiles crunch underfoot, mixed with crushed brick.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room73", "south",
        "chapter/prologue/area/sunken/room1018", "west",
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
