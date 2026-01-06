inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room581", "south",
        "domain/original/area/forest/room595", "west",
        "domain/original/area/forest/room584", "northeast",
        "domain/original/area/forest/room582", "east",
        "domain/original/area/forest/room586", "north",
    });
}
