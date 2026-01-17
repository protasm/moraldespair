inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Faded Narrow Way";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Carved blocks\n"
                "are shattered and glazed in places, a mix of chisel scars and burn pits. The way\n"
                "runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale\n"
                "mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1522", "north",
        "domain/original/area/indel/room1524", "south",
    });
}
