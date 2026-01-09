inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Shattered Narrow Way";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Masonry slumps inward, its edges scored and melted in places.\n\nThe way runs on in a narrow line, hemmed by broken walls. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1553", "east",
        "domain/original/area/indel/room1551", "west",
    });
}
