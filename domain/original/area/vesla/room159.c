inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Main street";
    long_desc = "South Main street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room158", "south",
        "domain/original/area/vesla/room125", "north",
    });
}
