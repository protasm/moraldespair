inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle Road Courtyard";
    long_desc = "Castle Road Courtyard.\n";
    dest_dir = ({
        "domain/original/area/indel/room1403", "north",
        "domain/original/area/indel/room1405", "south",
        "domain/original/area/indel/room1627", "east",
        "domain/original/area/indel/room1626", "west",
    });
}
