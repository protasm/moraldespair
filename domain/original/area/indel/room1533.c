inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Faded Split Way";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. The stonework\n"
                "is torn open, exposing fill and roots, with scorch marks in the cracks. The path\n"
                "splits around a heap of fallen blocks, offering lines gone to ruin. Moss and\n"
                "pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1532", "north",
        "domain/original/area/indel/room1534", "south",
        "domain/original/area/indel/room1597", "east",
    });
}
