inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Choked End";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, forcing a retreat. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1603", "west",
    });
}
