inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sunk Narrow Way";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Masonry slumps inward, its edges scored and melted in places. The way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1551", "east",
        "domain/original/area/indel/room1549", "west",
    });
}
