inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Splintered Sunk Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp.\n"
                "Masonry slumps inward, its edges scored and melted in places. The way runs on in\n"
                "a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling\n"
                "to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1552", "east",
        "domain/original/area/indel/room1550", "west",
    });
}
