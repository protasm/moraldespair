inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stink Alley Way";
    long_desc = "Stink Alley Way";
    dest_dir = ({
        "domain/original/area/vesla/room805", "south",
        "domain/original/area/vesla/room803", "west",
        "domain/original/area/vesla/room799", "east",
        "domain/original/area/vesla/room807", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "south");
    add_action("block_exit", "north");
}

int block_exit() {
    write("There is only debris; the structure collapsed years ago.\n");
    return 1;
}
