inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Spalled Narrow Way";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Blackened\n"
                "streaks and gouges run along the masonry, breaking any clean line. The way runs\n"
                "on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold\n"
                "cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1428", "north",
        "domain/original/area/indel/room1430", "south",
    });
}
