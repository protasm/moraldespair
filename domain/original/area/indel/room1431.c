inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Split Bleached Narrow Way";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams.\n"
                "Fragments of arches and lintels hang at odd angles, cut and burned through.\n"
                "\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Moss\n"
                "and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1430", "north",
        "domain/original/area/indel/room1432", "south",
    });
}
