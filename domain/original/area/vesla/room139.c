inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Basalt Avenue";
    long_desc = "Basalt Avenue";
    dest_dir = ({
        "domain/original/area/vesla/room140", "south",
        "domain/original/area/vesla/room853", "west",
        "domain/original/area/vesla/room854", "east",
        "domain/original/area/vesla/room138", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "west");
    add_action("block_exit", "east");
}

int block_exit() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
