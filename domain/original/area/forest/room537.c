inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "River Bank";
    long_desc = "River Bank.\n";
    dest_dir = ({
        "domain/original/area/forest/room538", "southwest",
        "domain/original/area/forest/room536", "northeast",
    });
}
