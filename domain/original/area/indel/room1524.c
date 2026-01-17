inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Leaning Faded Narrow Way";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. Carved blocks\n"
                "are shattered and glazed in places, a mix of chisel scars and burn pits. The way\n"
                "runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale\n"
                "mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1523", "north",
        "domain/original/area/indel/room1525", "south",
    });
}
