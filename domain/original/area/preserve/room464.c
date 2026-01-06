inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Nature Preserve";
    long_desc = "Nature Preserve.\n";
    dest_dir = ({
        "domain/original/area/preserve/room486", "west",
        "domain/original/area/preserve/room465", "east",
        "domain/original/area/preserve/room462", "south",
    });
}
