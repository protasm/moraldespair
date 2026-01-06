inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room539", "southwest",
        "domain/original/area/forest/room541", "northeast",
        "domain/original/area/forest/room549", "east",
        "domain/original/area/forest/room550", "south",
    });
}
