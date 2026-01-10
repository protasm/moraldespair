inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wall Street";
    long_desc = "Wall Street";
    dest_dir = ({
        "domain/original/area/vesla/room183", "east",
    });
}
