inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "New Tunnel: Checkpoint";
    long_desc = "New Tunnel: Checkpoint.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1302", "east",
        "domain/original/area/barb-caves/room1297", "west",
    });
}
