inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sunk Narrow Way";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Masonry slumps\n"
                "inward, its edges scored and melted in places. The way runs on in a narrow line,\n"
                "hemmed by broken walls left to weather. Moss and pale mold cling to the damp\n"
                "pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1557", "east",
        "domain/original/area/indel/room1555", "west",
    });
}
