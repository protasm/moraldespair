inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Fractured Narrow Way";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and\n"
                "hollows. Carved blocks are shattered and glazed in places, a mix of chisel scars\n"
                "and burn pits.\n"
                "\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Moss\n"
                "and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1521", "north",
        "domain/original/area/indel/room1523", "south",
    });
}
