inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Silted Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1562", "north",
        "domain/original/area/indel/room1560", "south",
    });
}
