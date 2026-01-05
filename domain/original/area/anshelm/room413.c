inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hawaiian Ryan's";
    long_desc = "Hawaiian Ryan's.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room238", "east",
        "domain/original/area/anshelm/room414", "north",
    });
}
