inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Merchant's Row, south of Big Bob's Sign Shop";
    long_desc = "West Merchant's Row, south of Big Bob's Sign Shop.\n";
    dest_dir = ({
        "domain/original/area/indel/room1590", "south",
        "domain/original/area/indel/room1408", "east",
        "domain/original/area/indel/room1410", "west",
    });
}
