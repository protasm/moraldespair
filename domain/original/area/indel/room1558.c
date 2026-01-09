inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Seamed Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1559", "north",
        "domain/original/area/indel/room1544", "south",
    });
}
