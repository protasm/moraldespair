inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Old Temple";
    long_desc = "The Old Temple\n";
    dest_dir = ({
        "domain/original/area/vesla/room130", "north",
    });
}
