inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Leaning Narrow Way";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1422", "north",
        "domain/original/area/indel/room1424", "south",
    });
}
