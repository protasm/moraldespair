inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of North Main and Scholar's Way";
    long_desc = "Intersection of North Main and Scholar's Way\n";
    dest_dir = ({
        "domain/original/area/vesla/room165", "south",
        "domain/original/area/vesla/room192", "east",
        "domain/original/area/vesla/room167", "north",
    });
}
