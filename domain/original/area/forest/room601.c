inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Large home";
    long_desc = "Large home.\n";
    dest_dir = ({
        "domain/original/area/forest/room567", "east",
    });
}
