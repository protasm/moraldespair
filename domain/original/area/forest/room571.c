inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room570", "southwest",
        "domain/original/area/forest/room572", "northeast",
        "domain/original/area/forest/room562", "west",
        "domain/original/area/forest/room561", "north",
    });
}
