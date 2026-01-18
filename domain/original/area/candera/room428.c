inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Drifted Platform";
    long_desc = "Scattered piers suggest a once-long span, now broken into bays. Wind has piled sand against one side, leaving the other scoured bare.";
    dest_dir = ({
        "domain/original/area/candera/room97", "south",
        "domain/original/area/candera/room977", "west",
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
