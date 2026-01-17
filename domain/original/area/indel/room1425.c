inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Silted Bleached Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp.\n"
                "Blackened streaks and gouges run along the masonry, breaking any clean line. The\n"
                "way runs on in a narrow line, hemmed by broken walls left to weather. Moss and\n"
                "pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1424", "north",
        "domain/original/area/indel/room1426", "south",
    });
}
