inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern slave bazaar";
    long_desc = "Eastern slave bazaar.\n";
    dest_dir = ({
        "domain/original/area/island/room732", "west",
        "domain/original/area/island/room730", "north",
    });
}
