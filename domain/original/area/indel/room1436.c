inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Faded Narrow Way";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Fragments of arches and lintels hang at odd angles, cut and burned through. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1435", "north",
        "domain/original/area/indel/room1437", "south",
    });
}
