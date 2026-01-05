inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Merchant's Row";
    long_desc = "East Merchant's Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1518", "east",
        "domain/original/area/indel/room1516", "west",
    });
}
