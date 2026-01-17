inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Collapsed Split Way";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. The\n"
                "remains of pillars stand jagged, split and fused by old force. The path splits\n"
                "around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold\n"
                "cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1623", "north",
        "domain/original/area/indel/room1511", "east",
        "domain/original/area/indel/room1509", "west",
    });
}
