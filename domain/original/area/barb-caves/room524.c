inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Passage Way";
    long_desc = "Passage Way.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room525", "south",
        "domain/original/area/barb-caves/room523", "north",
    });
}
