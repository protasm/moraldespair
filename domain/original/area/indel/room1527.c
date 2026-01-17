inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Slick Faded Narrow Way";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams.\n"
                "The stonework is torn open, exposing fill and roots, with scorch marks in the\n"
                "cracks.\n"
                "\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Moss\n"
                "and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1526", "north",
        "domain/original/area/indel/room1528", "south",
    });
}
