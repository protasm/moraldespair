inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cave Waterfall";
    long_desc = "Cave Waterfall.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room518", "northeast",
    });
}
