inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Merchant's Row, south of Sithicus";
    long_desc = "East Merchant's Row, south of Sithicus.\n";
    dest_dir = ({
        "domain/original/area/indel/room1621", "north",
        "domain/original/area/indel/room1515", "east",
        "domain/original/area/indel/room1513", "west",
    });
}
