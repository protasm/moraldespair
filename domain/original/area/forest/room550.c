inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest";
    long_desc = "A forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room539", "west",
        "domain/original/area/forest/room552", "south",
        "domain/original/area/forest/room551", "southwest",
        "domain/original/area/forest/room549", "northeast",
        "domain/original/area/forest/room553", "east",
        "domain/original/area/forest/room540", "north",
    });
}
