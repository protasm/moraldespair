inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Faded Split Way";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering multiple ruined lines. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1621", "north",
        "domain/original/area/indel/room1515", "east",
        "domain/original/area/indel/room1513", "west",
    });
}
