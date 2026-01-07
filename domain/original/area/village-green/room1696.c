inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northeastern Green";
    long_desc = "Northeastern Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1695", "west",
        "domain/original/area/village-green/room1697", "east",
        "domain/original/area/village-green/room1703", "south",
    });
}
