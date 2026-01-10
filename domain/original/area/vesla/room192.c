inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scholar's Way";
    long_desc = "Scholar's Way";
    dest_dir = ({
        "domain/original/area/vesla/room166", "west",
        "domain/original/area/vesla/room191", "east",
        "domain/original/area/vesla/room744", "south",
    });
}

void init() {
    ::init();
    add_action("block_exit", "south");
}

int block_exit() {
    write("Just ruins and broken stone remain; the structure gave out long ago.\n");
    return 1;
}
