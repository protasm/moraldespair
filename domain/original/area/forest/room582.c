inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Forest Mound";
    long_desc = "Forest Mound.\n";
    dest_dir = ({
        "domain/original/area/forest/room585", "west",
        "domain/original/area/forest/room581", "southwest",
        "domain/original/area/forest/room583", "northeast",
        "domain/original/area/forest/room599", "east",
        "domain/original/area/forest/room584", "north",
    });
}
