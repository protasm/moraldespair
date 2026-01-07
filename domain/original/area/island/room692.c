inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Power System Internals";
    long_desc = "Power System Internals.\n";
    dest_dir = ({
        "domain/original/area/island/room691", "west",
    });
}
