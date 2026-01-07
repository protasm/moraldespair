inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Trade Road";
    long_desc = "Deep ruts and gouges cut through the roadway, as if something massive scraped along it. Ash and shattered stone choke the old caravan path.\n";
    dest_dir = ({
        "domain/original/area/vesla/room172", "south",
        "domain/original/area/vesla/room232", "west",
        "domain/original/area/vesla/room736", "east",
        "domain/original/area/vesla/room174", "north",
    });
}

void init() {
    ::init();
    add_action("block_structure", "east");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
