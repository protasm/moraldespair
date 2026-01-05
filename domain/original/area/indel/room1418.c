inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pier Street and Merchant's Row";
    long_desc = "Pier Street and Merchant's Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1448", "north",
        "domain/original/area/indel/room1419", "south",
        "domain/original/area/indel/room1417", "east",
    });
}
