inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Twisting Tunnel";
    long_desc = "Twisting Tunnel.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1320", "southwest",
        "domain/original/area/barb-caves/room1325", "west",
        "domain/original/area/barb-caves/room1322", "southeast",
        "domain/original/area/barb-caves/room1324", "north",
    });
}
