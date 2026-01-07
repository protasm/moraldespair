inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northeast Green";
    long_desc = "Northeast Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1706", "south",
        "domain/original/area/village-green/room1703", "west",
        "domain/original/area/village-green/room1710", "east",
        "domain/original/area/village-green/room1697", "north",
    });
}
