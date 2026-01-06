inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room589", "west",
        "domain/original/area/forest/room580", "south",
        "domain/original/area/forest/room597", "southwest",
        "domain/original/area/forest/room589", "northeast",
        "domain/original/area/forest/room581", "east",
        "domain/original/area/forest/room588", "north",
    });
}
