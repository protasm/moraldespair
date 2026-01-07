inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scorched Basalt Avenue";
    long_desc = "Basalt blocks are cracked and glassy, fused by ancient dragonfire. The avenue runs like a blackened scar through the ruins.\n";
    dest_dir = ({
        "domain/original/area/vesla/room139", "south",
        "domain/original/area/vesla/room856", "west",
        "domain/original/area/vesla/room855", "east",
        "domain/original/area/vesla/room137", "north",
    });
}

void init() {
    add_action("block_structure", "west");
    add_action("block_structure", "east");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
