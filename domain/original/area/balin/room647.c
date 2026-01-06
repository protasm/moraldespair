inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gnome Hut";
    long_desc = "Gnome Hut.\n";
    dest_dir = ({
        "domain/original/area/balin/room643", "north",
    });
}
