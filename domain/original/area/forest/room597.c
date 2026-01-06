inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room590", "west",
        "domain/original/area/forest/room579", "south",
        "domain/original/area/forest/room596", "southwest",
        "domain/original/area/forest/room598", "northeast",
        "domain/original/area/forest/room580", "east",
        "domain/original/area/forest/room589", "north",
    });
}
