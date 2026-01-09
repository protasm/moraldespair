inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Fractured Sunk Narrow Way";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Jagged ribs of stone show cuts and pitting, some edges glassed by heat.\n\nThe way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1535", "east",
        "domain/original/area/indel/room1556", "west",
    });
}
