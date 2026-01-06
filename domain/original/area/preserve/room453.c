inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Nature Preserve";
    long_desc = "Nature Preserve.\n";
    dest_dir = ({
        "domain/original/area/preserve/room455", "south",
        "domain/original/area/preserve/room452", "east",
        "domain/original/area/preserve/room454", "north",
    });
}
