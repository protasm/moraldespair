inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northern Main street";
    long_desc = "Northern Main street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room166", "south",
        "domain/original/area/vesla/room168", "north",
    });
}
