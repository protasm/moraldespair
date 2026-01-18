inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Darkened Crossing";
    long_desc = "Two streets cross in a square of uneven stone. The corners are piled with broken masonry and grit.";
    dest_dir = ({
        "domain/original/area/vesla/room165", "south",
        "domain/original/area/vesla/room192", "east",
        "domain/original/area/vesla/room167", "north",
    });
}

