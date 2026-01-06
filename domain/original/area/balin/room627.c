inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern Beach";
    long_desc = "Eastern Beach.\n";
    dest_dir = ({
        "domain/original/area/balin/room626", "west",
    });
}
