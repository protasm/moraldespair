inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A desert plain";
    long_desc = "A desert plain.\n";
    dest_dir = ({
        "domain/original/area/island/room628", "west",
        "domain/original/area/island/room630", "north",
    });
}
