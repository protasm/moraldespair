inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Fallen Sunk Narrow Way";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Jagged ribs of\n"
                "stone show cuts and pitting, some edges glassed by heat. The way runs on in a\n"
                "narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to\n"
                "the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1564", "north",
        "domain/original/area/indel/room1562", "south",
    });
}
