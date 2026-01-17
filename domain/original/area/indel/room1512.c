inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Ashen Faded Narrow Way";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and\n"
                "hollows. The remains of pillars stand jagged, split and fused by old force.\n"
                "\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Moss\n"
                "and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1513", "east",
        "domain/original/area/indel/room1511", "west",
    });
}
