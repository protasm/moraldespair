inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Pitted Narrow Way";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Masonry slumps\n"
                "inward, its edges scored and melted in places. The way runs on in a narrow line,\n"
                "hemmed by broken walls left to weather. Moss and pale mold cling to the damp\n"
                "pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1556", "east",
        "domain/original/area/indel/room1554", "west",
    });
}
