inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Crossing";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several lines of ruin meet. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1401", "north",
        "domain/original/area/indel/room1403", "south",
        "domain/original/area/indel/room1633", "east",
        "domain/original/area/indel/room1631", "west",
    });
}
