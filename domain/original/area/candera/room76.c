inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sand-Choked Lane";
    long_desc = "A wide run of cracked stone stretches north and south, its center scoured to\ndust. Soot stains cling to the stone, and the air tastes of old smoke.\n\nNo footprints remain; only layered grit records the years.\n";
    dest_dir = ({
        "domain/original/area/candera/room86", "north",
        "domain/original/area/candera/room78", "south",
        "domain/original/area/candera/room75", "east",
        "domain/original/area/candera/room77", "west",
    });
}

void init() {
    ::init();
    add_action("block_exit", "west");
}

int block_exit() {
    write("The way is blocked by a wall of broken stone.\n");
    return 1;
}
