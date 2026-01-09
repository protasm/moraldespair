inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Blackened Passage";
    long_desc = "Broken masonry and cinders blanket the floor. Melted fixtures "
        + "cling to the walls, and clawed furrows cut through the rubble.\n";
    dest_dir = ({
        "domain/original/area/vesla/room223", "west",
        "domain/original/area/vesla/room221", "east",
        "domain/original/area/vesla/room119", "north",
    });
}
