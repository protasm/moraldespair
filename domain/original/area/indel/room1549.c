inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sagging Narrow Way";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Masonry\n"
                "slumps inward, its edges scored and melted in places. The way runs on in a\n"
                "narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to\n"
                "the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1550", "east",
        "domain/original/area/indel/room1548", "west",
    });
}
