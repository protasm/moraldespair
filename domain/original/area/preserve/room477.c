inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Nature Preserve";
    long_desc = "Nature Preserve.\n";
    dest_dir = ({
        "domain/original/area/preserve/room478", "southwest",
        "domain/original/area/preserve/room476", "southeast",
        "domain/original/area/preserve/room490", "north",
    });
}
