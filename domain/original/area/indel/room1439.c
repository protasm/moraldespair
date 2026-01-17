inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Faded Choked End";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Fragments of\n"
                "arches and lintels hang at odd angles, cut and burned through. A collapsed heap\n"
                "chokes the line, the passage left to cave in. Moss and pale mold cling to the\n"
                "damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1438", "north",
    });
}
