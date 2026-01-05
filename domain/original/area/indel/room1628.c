inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Zomar's Dry Goods";
    long_desc = "Zomar's Dry Goods.\n";
    dest_dir = ({
        "domain/original/area/indel/room1403", "east",
        "domain/original/area/indel/room1629", "down",
    });
}
