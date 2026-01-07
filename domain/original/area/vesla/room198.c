inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ash-Choked Ruined Boulevard";
    long_desc = "Fine ash has settled in drifts along the boulevard, muffling the crunch of broken stone. The road is deserted and choked with gray dust.\n";
    dest_dir = ({
        "domain/original/area/vesla/room199", "south",
        "domain/original/area/vesla/room857", "east",
        "domain/original/area/vesla/room197", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "east");
}

int block_exit() {
    write("Rubble blocks the way; the structure has long since fallen.\n");
    return 1;
}
