inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sunk Narrow Way";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. Chunks of wall\n"
                "have been scooped away, leaving raw ribs of stone. The way runs on in a narrow\n"
                "line, hemmed by broken walls left to weather. Moss and pale mold cling to the\n"
                "damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1558", "north",
        "domain/original/area/indel/room1543", "south",
    });
}
