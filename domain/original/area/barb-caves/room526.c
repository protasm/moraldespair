inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Circular room";
    long_desc = "Circular room.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room525", "north",
    });
}
