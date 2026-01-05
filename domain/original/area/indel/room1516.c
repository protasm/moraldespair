inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Merchant's Row and Pensji Lane";
    long_desc = "Merchant's Row and Pensji Lane.\n";
    dest_dir = ({
        "domain/original/area/indel/room1520", "south",
        "domain/original/area/indel/room1517", "east",
        "domain/original/area/indel/room1515", "west",
    });
}
