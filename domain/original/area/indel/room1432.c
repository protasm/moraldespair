inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Fragments of arches and lintels hang at odd angles, cut and burned through. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1431", "north",
        "domain/original/area/indel/room1433", "south",
    });
}
