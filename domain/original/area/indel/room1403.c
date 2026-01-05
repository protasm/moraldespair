inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle Road";
    long_desc = "Castle Road.\n";
    dest_dir = ({
        "domain/original/area/indel/room1402", "north",
        "domain/original/area/indel/room1404", "south",
        "domain/original/area/indel/room1630", "east",
        "domain/original/area/indel/room1628", "west",
    });
}
