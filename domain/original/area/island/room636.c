inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road";
    long_desc = "Balin Road.\n";
    dest_dir = ({
        "domain/original/area/island/room722", "southwest",
        "domain/original/area/island/room635", "east",
        "domain/original/area/island/room721", "southeast",
        "domain/original/area/island/room637", "west",
    });
}
