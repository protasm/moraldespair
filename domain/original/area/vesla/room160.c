inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northern Main";
    long_desc = "Northern Main\n";
    dest_dir = ({
        "domain/original/area/vesla/room125", "south",
        "domain/original/area/vesla/room412", "east",
        "domain/original/area/vesla/room161", "north",
    });
}
