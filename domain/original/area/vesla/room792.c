inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Choked Alleyway";
    long_desc = "Broken walls lean inward over a narrow way packed with debris."
        + " The alley is quiet, the stones scorched by long-ago flames.\n";
    dest_dir = ({
        "domain/original/area/vesla/room410", "south",
        "domain/original/area/vesla/room795", "east",
        "domain/original/area/vesla/room794", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "north");
}

int block_exit() {
    write("The way ends in collapsed ruins; only debris remains.\n");
    return 1;
}
