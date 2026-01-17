inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Choked End";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. Fragments of\n"
                "arches and lintels hang at odd angles, cut and burned through. A collapsed heap\n"
                "chokes the line, the passage left to cave in. Thin lichen mats the shaded edges,\n"
                "and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1603", "west",
    });
}
