inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Scorched Choked End";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1448", "south",
    });
}
