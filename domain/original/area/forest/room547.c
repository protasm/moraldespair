inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room542", "west",
        "domain/original/area/forest/room555", "south",
        "domain/original/area/forest/room548", "southwest",
        "domain/original/area/forest/room546", "northeast",
        "domain/original/area/forest/room556", "east",
        "domain/original/area/forest/room543", "north",
    });
}
