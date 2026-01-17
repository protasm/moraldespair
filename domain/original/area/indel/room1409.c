inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Split Way";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Walls to either\n"
                "side are chewed by blasts and blade scars, their faces peeled away. The path\n"
                "splits around a heap of fallen blocks, offering lines gone to ruin. Moss and\n"
                "pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1590", "south",
        "domain/original/area/indel/room1408", "east",
        "domain/original/area/indel/room1410", "west",
    });
}
