inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Passage Way";
    long_desc = "Passage Way.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room520", "south",
        "domain/original/area/barb-caves/room517", "west",
        "domain/original/area/barb-caves/room523", "east",
        "domain/original/area/barb-caves/room521", "north",
    });
}
