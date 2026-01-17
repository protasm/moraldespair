inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Smeared Bleached Split Way";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time.\n"
                "Fragments of arches and lintels hang at odd angles, cut and burned through. The\n"
                "path splits around a heap of fallen blocks, offering lines gone to ruin. Moss\n"
                "and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1433", "north",
        "domain/original/area/indel/room1435", "south",
        "domain/original/area/indel/room1545", "east",
    });
}
