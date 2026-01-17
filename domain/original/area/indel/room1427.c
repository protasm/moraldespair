inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Narrow Way";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Blackened\n"
                "streaks and gouges run along the masonry, breaking any clean line. The way runs\n"
                "on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold\n"
                "cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1426", "north",
        "domain/original/area/indel/room1428", "south",
    });
}
