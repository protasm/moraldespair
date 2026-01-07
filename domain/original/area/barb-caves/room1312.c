inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Twisting Tunnel";
    long_desc = "Twisting Tunnel.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1311", "southwest",
        "domain/original/area/barb-caves/room1313", "north",
    });
}
