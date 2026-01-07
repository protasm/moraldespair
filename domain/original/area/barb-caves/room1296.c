inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "New Tunnel";
    long_desc = "New Tunnel.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1295", "west",
    });
}
