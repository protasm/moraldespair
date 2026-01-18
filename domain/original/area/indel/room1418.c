inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Split Way";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1448", "north",
        "domain/original/area/indel/room1419", "south",
        "domain/original/area/indel/room1417", "east",
    });
}
