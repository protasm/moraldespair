inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Blasted Sunk Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Masonry\n"
                "slumps inward, its edges scored and melted in places. The way runs on in a\n"
                "narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to\n"
                "the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1549", "east",
        "domain/original/area/indel/room1547", "west",
    });
}
