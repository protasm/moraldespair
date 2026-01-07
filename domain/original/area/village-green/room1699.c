inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southwest Green";
    long_desc = "Southwest Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1713", "south",
        "domain/original/area/village-green/room1700", "east",
        "domain/original/area/village-green/room1689", "north",
    });
}
