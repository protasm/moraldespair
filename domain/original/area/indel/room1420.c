inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Stained Narrow Way";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
    dest_dir = ({
        "domain/original/area/indel/room1419", "north",
        "domain/original/area/indel/room1421", "south",
    });
}
