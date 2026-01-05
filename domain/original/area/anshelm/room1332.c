inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southern statuary";
    long_desc = "Southern statuary.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1330", "north",
    });
}
