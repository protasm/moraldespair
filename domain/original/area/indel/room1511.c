inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Merchant's Row, south of Mother Whitman's";
    long_desc = "East Merchant's Row, south of Mother Whitman's.\n";
    dest_dir = ({
        "domain/original/area/indel/room1622", "north",
        "domain/original/area/indel/room1512", "east",
        "domain/original/area/indel/room1510", "west",
    });
}
