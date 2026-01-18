inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Split Way";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1590", "south",
        "domain/original/area/indel/room1408", "east",
        "domain/original/area/indel/room1410", "west",
    });
}
