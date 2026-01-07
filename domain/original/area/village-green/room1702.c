inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southeast Green";
    long_desc = "Southeast Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1714", "south",
        "domain/original/area/village-green/room1701", "west",
        "domain/original/area/village-green/room1707", "east",
        "domain/original/area/village-green/room1692", "north",
    });
}
