inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Throne Room";
    long_desc = "Throne Room.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room525", "east",
    });
}
