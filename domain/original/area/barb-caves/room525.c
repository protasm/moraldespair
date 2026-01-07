inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Passage Way";
    long_desc = "Passage Way.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1293", "west",
        "domain/original/area/barb-caves/room526", "south",
        "domain/original/area/barb-caves/room524", "north",
    });
}
