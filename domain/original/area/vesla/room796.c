inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Choked Alley";
    long_desc = "The alley is little more than a trench of shattered stone and collapsed timbers. Ash and rubble fill the cramped passage.\n";
    dest_dir = ({
        "domain/original/area/vesla/room814", "south",
        "domain/original/area/vesla/room795", "west",
        "domain/original/area/vesla/room231", "east",
        "domain/original/area/vesla/room961", "north",
    });
}

void init() {
    ::init();
    add_action("block_structure", "south");
    add_action("block_structure", "north");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
