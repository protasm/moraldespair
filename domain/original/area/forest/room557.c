inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest";
    long_desc = "A forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room546", "west",
        "domain/original/area/forest/room561", "south",
        "domain/original/area/forest/room556", "southwest",
        "domain/original/area/forest/room558", "northeast",
        "domain/original/area/forest/room560", "east",
        "domain/original/area/forest/room545", "north",
    });
}
