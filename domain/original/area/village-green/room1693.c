inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northwestern Green";
    long_desc = "Northwestern Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1687", "west",
        "domain/original/area/village-green/room1695", "east",
        "domain/original/area/village-green/room1694", "south",
    });
}
