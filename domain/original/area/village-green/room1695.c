inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northwestern Green";
    long_desc = "Northwestern Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1693", "west",
        "domain/original/area/village-green/room1696", "east",
        "domain/original/area/village-green/room1704", "south",
    });
}
