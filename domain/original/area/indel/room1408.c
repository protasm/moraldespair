inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Rubble Split Way";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The path splits around a heap of fallen blocks, offering multiple ruined lines. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1589", "south",
        "domain/original/area/indel/room1407", "east",
        "domain/original/area/indel/room1409", "west",
    });
}
