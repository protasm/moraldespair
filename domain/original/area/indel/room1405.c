inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Choked Split Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The path splits around a heap of fallen blocks, offering multiple ruined lines. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1404", "north",
        "domain/original/area/indel/room1406", "south",
        "domain/original/area/indel/room1625", "west",
    });
}
