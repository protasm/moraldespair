inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western slave bazaar";
    long_desc = "Western slave bazaar.\n";
    dest_dir = ({
        "domain/original/area/balin/room732", "east",
        "domain/original/area/balin/room727", "north",
    });
}
