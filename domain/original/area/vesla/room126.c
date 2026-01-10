inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The end of the park street";
    long_desc = "The end of the park street";
    dest_dir = ({
        "domain/original/area/vesla/room880", "south",
        "domain/original/area/vesla/room127", "west",
        "domain/original/area/vesla/room125", "east",
        "domain/original/area/vesla/room879", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "south");
    add_action("block_exit", "north");
}

int block_exit() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
