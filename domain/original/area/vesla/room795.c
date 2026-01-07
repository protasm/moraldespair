inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Choked Alleyway";
    long_desc = "Broken walls lean inward over a narrow way packed with debris. The alley is quiet, the stones scorched by long-ago flames.\n";
    dest_dir = ({
        "domain/original/area/vesla/room813", "south",
        "domain/original/area/vesla/room792", "west",
        "domain/original/area/vesla/room796", "east",
        "domain/original/area/vesla/room797", "north",
    });
}

void init() {
    ::init();
    add_action("block_structure", "south");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
