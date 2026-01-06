inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A small clearing";
    long_desc = "A small clearing.\n";
    dest_dir = ({
        "domain/original/area/forest/room582", "west",
    });
}
