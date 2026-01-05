inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northern Main Street";
    long_desc = "Northern Main Street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room162", "south",
        "domain/original/area/vesla/room811", "east",
        "domain/original/area/vesla/room164", "north",
    });
}
