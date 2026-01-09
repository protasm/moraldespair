inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Charred Bleached Narrow Way";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1406", "east",
        "domain/original/area/indel/room1408", "west",
    });
}
