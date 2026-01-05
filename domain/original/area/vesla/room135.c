inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Basalt Avenue";
    long_desc = "Basalt Avenue.\n";
    dest_dir = ({
        "domain/original/area/vesla/room136", "south",
        "domain/original/area/vesla/room133", "north",
    });
}
