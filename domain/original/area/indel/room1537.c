inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Broken Narrow Way";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Chunks of wall have been scooped away, leaving raw ribs of stone.\n\nThe way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1538", "east",
        "domain/original/area/indel/room1536", "west",
    });
}
