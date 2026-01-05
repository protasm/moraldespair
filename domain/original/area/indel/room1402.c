inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle Road";
    long_desc = "Castle Road.\n";
    dest_dir = ({
        "domain/original/area/indel/room1401", "north",
        "domain/original/area/indel/room1403", "south",
        "domain/original/area/indel/room1633", "east",
        "domain/original/area/indel/room1631", "west",
    });
}
