inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Kitchen";
    long_desc = "Kitchen.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room521", "south",
    });
}
