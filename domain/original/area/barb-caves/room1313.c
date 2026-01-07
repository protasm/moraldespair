inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Twisting Tunnel";
    long_desc = "Twisting Tunnel.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1314", "east",
        "domain/original/area/barb-caves/room1316", "northwest",
        "domain/original/area/barb-caves/room1312", "south",
    });
}
