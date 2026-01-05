inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Pier Street";
    long_desc = "South Pier Street.\n";
    dest_dir = ({
        "domain/original/area/indel/room1430", "north",
        "domain/original/area/indel/room1432", "south",
    });
}
