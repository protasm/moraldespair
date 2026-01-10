inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Via Sacra";
    long_desc = "Via Sacra\n";
    dest_dir = ({
        "domain/original/area/vesla/room408", "west",
        "domain/original/area/vesla/room216", "south",
        "domain/original/area/vesla/room218", "north",
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
