inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Blackened Passage";
    long_desc = "Broken masonry and cinders blanket the floor. Melted fixtures "
        + "cling to the walls, and clawed furrows cut through the rubble.\n";
    dest_dir = ({
        "domain/original/area/vesla/room216", "east",
    });
}
