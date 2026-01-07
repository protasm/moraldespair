inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Desecrated Ruined Avenue";
    long_desc = "Charred pillars and shattered altars line the once-holy way. The stones are cracked and cold, abandoned for two centuries.\n";
    dest_dir = ({
        "domain/original/area/vesla/room215", "south",
        "domain/original/area/vesla/room402", "west",
        "domain/original/area/vesla/room403", "east",
        "domain/original/area/vesla/room217", "north",
    });
}

void init() {
    ::init();
    add_action("block_exit", "west");
}

int block_exit() {
    write("The passage is choked with debris; you cannot pass.\n");
    return 1;
}
