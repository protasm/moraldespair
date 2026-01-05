inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Merchant's Row, south of Knights of Solamnia";
    long_desc = "West Merchant's Row, south of Knights of Solamnia.\n";
    dest_dir = ({
        "domain/original/area/indel/room1412", "east",
        "domain/original/area/indel/room1414", "west",
    });
}
