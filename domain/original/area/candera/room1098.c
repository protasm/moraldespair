inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "broken passage";
    long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire-blackened patches run along the base of the walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room82", "west",
        "domain/original/area/candera/room1099", "down",
    });
}

void init() {
    ::init();
    add_action("block_exit", "down");
}

int block_exit() {
    write("The way is blocked by a wall of broken stone.\n");
    return 1;
}
