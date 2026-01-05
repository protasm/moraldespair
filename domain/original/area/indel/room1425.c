inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pier Street";
    long_desc = "Pier Street.\n";
    dest_dir = ({
        "domain/original/area/indel/room1424", "north",
        "domain/original/area/indel/room1426", "south",
    });
}
