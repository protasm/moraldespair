inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Feed room";
    long_desc = "Feed room\n";
    dest_dir = ({
        "domain/original/area/vesla/room774", "north",
    });
}
