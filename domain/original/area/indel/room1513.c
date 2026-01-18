inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Blasted Narrow Way";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. The remains of pillars stand jagged, split and fused by old force. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1514", "east",
        "domain/original/area/indel/room1512", "west",
    });
}
