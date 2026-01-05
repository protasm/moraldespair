inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple of Water";
    long_desc = "Temple of Water.\n";
    dest_dir = ({
        "domain/original/area/candera/room91", "east",
        "domain/original/area/candera/room1132", "up",
    });
}
