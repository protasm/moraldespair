inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Merchant's Row, south of a livestock lot";
    long_desc = "East Merchant's Row, south of a livestock lot.\n";
    dest_dir = ({
        "domain/original/area/indel/room1623", "north",
        "domain/original/area/indel/room1511", "east",
        "domain/original/area/indel/room1509", "west",
    });
}
