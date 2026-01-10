inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East River Street";
    long_desc = "East River Street";
    dest_dir = ({
        "domain/original/area/vesla/room209", "west",
        "domain/original/area/vesla/room211", "east",
        "domain/original/area/vesla/room394", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "north");
}

int block_exit() {
    write("There is only debris; the structure collapsed years ago.\n");
    return 1;
}
