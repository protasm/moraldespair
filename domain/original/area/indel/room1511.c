inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Faded Split Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp.\n"
                "The remains of pillars stand jagged, split and fused by old force. The path\n"
                "splits around a heap of fallen blocks, offering lines gone to ruin. Moss and\n"
                "pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1622", "north",
        "domain/original/area/indel/room1512", "east",
        "domain/original/area/indel/room1510", "west",
    });
}
