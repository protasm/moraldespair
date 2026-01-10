inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "An alley";
    long_desc = "An alley";
    dest_dir = ({
        "domain/original/area/vesla/room814", "south",
        "domain/original/area/vesla/room795", "west",
        "domain/original/area/vesla/room231", "east",
        "domain/original/area/vesla/room961", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "south");
    add_action("block_exit", "north");
}

int block_exit() {
    write("The way ends in collapsed ruins; only debris remains.\n");
    return 1;
}
