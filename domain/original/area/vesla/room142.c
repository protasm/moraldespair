inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Basalt Avenue";
    long_desc = "Basalt Avenue";
    dest_dir = ({
        "domain/original/area/vesla/room143", "south",
        "domain/original/area/vesla/room850", "east",
        "domain/original/area/vesla/room141", "north",
    });
}
