inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Castle Road and Merchant's Row";
    long_desc = "Intersection of Castle Road and Merchant's Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1405", "north",
        "domain/original/area/indel/room1584", "south",
        "domain/original/area/indel/room1508", "east",
        "domain/original/area/indel/room1407", "west",
    });
}
