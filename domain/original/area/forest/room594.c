inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A riverbank";
    long_desc = "A riverbank.\n";
    dest_dir = ({
        "domain/original/area/forest/room593", "southwest",
        "domain/original/area/forest/room595", "northeast",
        "domain/original/area/forest/room589", "east",
        "domain/original/area/forest/room590", "south",
    });
}
