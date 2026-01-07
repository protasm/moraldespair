inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road";
    long_desc = "Balin Road.\n";
    dest_dir = ({
        "domain/original/area/balin/room722", "southwest",
        "domain/original/area/balin/room635", "east",
        "domain/original/area/balin/room721", "southeast",
        "domain/original/area/balin/room637", "west",
    });
}
