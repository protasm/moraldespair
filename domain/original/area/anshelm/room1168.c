inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Inner Bailey";
    long_desc = "The Inner Bailey.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1150", "north",
    });
}
