inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Basalt Avenue";
    long_desc = "Basalt Avenue.\n";
    dest_dir = ({
        "domain/original/area/vesla/room140", "south",
        "domain/original/area/vesla/room853", "west",
        "domain/original/area/vesla/room854", "east",
        "domain/original/area/vesla/room138", "north",
    });
}
