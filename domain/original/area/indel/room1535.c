inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Faded Narrow Way";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. The stonework\n"
                "is torn open, exposing fill and roots, with scorch marks in the cracks. The way\n"
                "runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale\n"
                "mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1536", "east",
        "domain/original/area/indel/room1557", "west",
    });
}
