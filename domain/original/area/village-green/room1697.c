inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northeast Green";
    long_desc = "Northeast Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1696", "west",
        "domain/original/area/village-green/room1698", "east",
        "domain/original/area/village-green/room1705", "south",
    });
}
