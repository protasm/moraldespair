inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room547", "west",
        "domain/original/area/forest/room562", "south",
        "domain/original/area/forest/room555", "southwest",
        "domain/original/area/forest/room557", "northeast",
        "domain/original/area/forest/room561", "east",
        "domain/original/area/forest/room546", "north",
    });
}
