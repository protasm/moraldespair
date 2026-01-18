inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wind-Scoured Reach";
    long_desc = "The way pinches tight, then opens again into scattered foundations. Ash and grit collect in corners, damped by occasional trickles.";
    dest_dir = ({
        "domain/original/area/candera/room989", "east",
        "domain/original/area/candera/room58", "west",
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
