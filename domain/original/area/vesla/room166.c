inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Main Scholar Crossing";
    long_desc = "Two streets cross in a square of uneven stone. The corners are piled with\n"
              + "broken masonry and grit.\n";
    dest_dir = ({
        "domain/original/area/vesla/room165", "south",
        "domain/original/area/vesla/room192", "east",
        "domain/original/area/vesla/room167", "north",
    });
}
