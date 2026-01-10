inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stink Alley Way";
    long_desc = "Stink Alley Way";
    dest_dir = ({
        "domain/original/area/vesla/room802", "east",
        "domain/original/area/vesla/room804", "south",
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
