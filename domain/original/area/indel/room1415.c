inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Merchant's Row, south of the Cobbler's Shop";
    long_desc = "West Merchant's Row, south of the Cobbler's Shop.\n";
    dest_dir = ({
        "domain/original/area/indel/room1414", "east",
        "domain/original/area/indel/room1416", "west",
    });
}
