inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Stained Faded Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1520", "north",
        "domain/original/area/indel/room1522", "south",
    });
}
