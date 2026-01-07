inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Barracks";
    long_desc = "Barracks.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room519", "north",
    });
}
