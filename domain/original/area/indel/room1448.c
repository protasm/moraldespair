inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "North Pier Street";
    long_desc = "North Pier Street.\n";
    dest_dir = ({
        "domain/original/area/indel/room1507", "north",
        "domain/original/area/indel/room1418", "south",
    });
}
