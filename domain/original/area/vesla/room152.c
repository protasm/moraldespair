inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Main street";
    long_desc = "South Main street\n";
    dest_dir = ({
        "domain/original/area/vesla/room151", "south",
        "domain/original/area/vesla/room819", "west",
        "domain/original/area/vesla/room817", "east",
        "domain/original/area/vesla/room153", "north",
    });
}

