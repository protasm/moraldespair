inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A river bank";
    long_desc = "A river bank.\n";
    dest_dir = ({
        "domain/original/area/forest/room594", "southwest",
        "domain/original/area/forest/room587", "northeast",
        "domain/original/area/forest/room585", "east",
        "domain/original/area/forest/room589", "south",
    });
}
