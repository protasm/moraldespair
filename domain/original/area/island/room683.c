inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Trophy Room";
    long_desc = "Trophy Room.\n";
    dest_dir = ({
        "domain/original/area/island/room682", "east",
    });
}
