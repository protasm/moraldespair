inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sunk Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1539", "east",
        "domain/original/area/indel/room1537", "west",
    });
}
