inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Jagged Split Way";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Chunks of wall have been scooped away, leaving raw ribs of stone. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1543", "north",
        "domain/original/area/indel/room1547", "east",
        "domain/original/area/indel/room1545", "west",
    });
}
