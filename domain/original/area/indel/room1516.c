inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Splintered Split Way";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering multiple ruined lines. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1520", "south",
        "domain/original/area/indel/room1517", "east",
        "domain/original/area/indel/room1515", "west",
    });
}
