inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Merchant's Row, north of the Silver Griffin";
    long_desc = "West Merchant's Row, north of the Silver Griffin.\n";
    dest_dir = ({
        "domain/original/area/indel/room1589", "south",
        "domain/original/area/indel/room1407", "east",
        "domain/original/area/indel/room1409", "west",
    });
}
