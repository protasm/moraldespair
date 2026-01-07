inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southwest Green";
    long_desc = "Southwest Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1719", "south",
        "domain/original/area/village-green/room1712", "east",
        "domain/original/area/village-green/room1699", "north",
    });
}
