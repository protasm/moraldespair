inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A river bank";
    long_desc = "A river bank.\n";
    dest_dir = ({
        "domain/original/area/forest/room536", "southwest",
        "domain/original/area/forest/room593", "northeast",
        "domain/original/area/forest/room591", "east",
        "domain/original/area/forest/room534", "south",
    });
}
