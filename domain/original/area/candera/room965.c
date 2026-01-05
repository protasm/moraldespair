inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A Jeweler's Shop";
    long_desc = "A Jeweler's Shop.\n";
    dest_dir = ({
        "domain/original/area/candera/room58", "east",
    });
}
