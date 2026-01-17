inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Seamed Bleached Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Blackened\n"
                "streaks and gouges run along the masonry, breaking any clean line. The way runs\n"
                "on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold\n"
                "cling to the damp pockets, and nothing moves except drifting grit.\n";
    dest_dir = ({
        "domain/original/area/indel/room1421", "north",
        "domain/original/area/indel/room1423", "south",
    });
}
