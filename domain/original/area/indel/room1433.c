inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Narrow Way";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Fragments of\n"
                "arches and lintels hang at odd angles, cut and burned through. The way runs on\n"
                "in a narrow line, hemmed by broken walls left to weather. Moss and pale mold\n"
                "cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1432", "north",
        "domain/original/area/indel/room1434", "south",
    });
}
