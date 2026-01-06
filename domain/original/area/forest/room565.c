inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room552", "west",
        "domain/original/area/forest/room574", "south",
        "domain/original/area/forest/room566", "southwest",
        "domain/original/area/forest/room564", "northeast",
        "domain/original/area/forest/room568", "east",
        "domain/original/area/forest/room553", "north",
    });
}
