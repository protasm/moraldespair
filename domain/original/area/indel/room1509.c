inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Rubble Faded Split Way";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. The remains\n"
                "of pillars stand jagged, split and fused by old force. The path splits around a\n"
                "heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to\n"
                "the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1624", "north",
        "domain/original/area/indel/room1510", "east",
        "domain/original/area/indel/room1508", "west",
    });
}
