inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruins in the Southeast Green";
    long_desc = "Ruins in the Southeast Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1707", "west",
        "domain/original/area/village-green/room1716", "south",
        "domain/original/area/village-green/room1709", "north",
    });
}
