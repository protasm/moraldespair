inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Smeared Bleached Split Way";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Fragments of arches and lintels hang at odd angles, cut and burned through. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1433", "north",
        "domain/original/area/indel/room1435", "south",
        "domain/original/area/indel/room1545", "east",
    });
}
