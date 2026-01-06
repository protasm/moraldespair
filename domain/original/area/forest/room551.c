inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room576", "south",
        "domain/original/area/forest/room531", "west",
        "domain/original/area/forest/room550", "northeast",
        "domain/original/area/forest/room552", "east",
        "domain/original/area/forest/room539", "north",
    });
}
