inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Desecrated Southern Ruined Avenue";
    long_desc = "Charred pillars and shattered altars line the once-holy way. The stones are cracked and cold, abandoned for two centuries.\n";
    dest_dir = ({
        "domain/original/area/vesla/room213", "south",
        "domain/original/area/vesla/room400", "west",
        "domain/original/area/vesla/room401", "east",
        "domain/original/area/vesla/room215", "north",
    });
}

void init() {
    ::init();
    add_action("block_structure", "west");
    add_action("block_structure", "east");
}

int block_structure() {
    write("A heap of collapsed stone blocks the way.\n");
    return 1;
}
