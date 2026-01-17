inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Choked End";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp.\n"
                "Fragments of arches and lintels hang at odd angles, cut and burned through. A\n"
                "collapsed heap chokes the line, the passage left to cave in. Thin lichen mats\n"
                "the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1600", "west",
    });
}
