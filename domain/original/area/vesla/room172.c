inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Caravan Road";
    long_desc = "Deep ruts and gouges cut through the roadway, as if something massive scraped along it. Ash and shattered stone choke the old caravan path.\n";
    dest_dir = ({
        "domain/original/area/vesla/room116", "south",
        "domain/original/area/vesla/room226", "west",
        "domain/original/area/vesla/room735", "east",
        "domain/original/area/vesla/room173", "north",
    });
}

void init() {
    add_action("block_structure", "east");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
