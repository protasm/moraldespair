inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southern Via Sacra";
    long_desc = "Southern Via Sacra";
    dest_dir = ({
        "domain/original/area/vesla/room213", "south",
        "domain/original/area/vesla/room400", "west",
        "domain/original/area/vesla/room401", "east",
        "domain/original/area/vesla/room215", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "west");
    add_action("block_exit", "east");
}

int block_exit() {
    write("A heap of collapsed stone blocks the way.\n");
    return 1;
}
