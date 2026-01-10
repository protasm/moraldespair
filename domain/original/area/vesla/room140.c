inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Basalt Avenue and Street of the Bells";
    long_desc = "Intersection of Basalt Avenue and Street of the Bells\n";
    dest_dir = ({
        "domain/original/area/vesla/room141", "south",
        "domain/original/area/vesla/room204", "east",
        "domain/original/area/vesla/room139", "north",
    });
}
