inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Worn Faded Narrow Way";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. The stonework is torn open, exposing fill and roots, with scorch marks in the cracks. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1537", "east",
        "domain/original/area/indel/room1535", "west",
    });
}
