inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stink Alley Way";
    long_desc = "Stink Alley Way";
    dest_dir = ({
        "domain/original/area/vesla/room799", "west",
        "domain/original/area/vesla/room801", "east",
        "domain/original/area/vesla/room806", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "north");
}

int block_exit() {
    write("Only shattered remains mark the spot; the building caved in long ago.\n");
    return 1;
}
