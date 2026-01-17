inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Worn Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp.\n"
                "Fragments of arches and lintels hang at odd angles, cut and burned through. The\n"
                "way runs on in a narrow line, hemmed by broken walls left to weather. Moss and\n"
                "pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1434", "north",
        "domain/original/area/indel/room1436", "south",
    });
}
