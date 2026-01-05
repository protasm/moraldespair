inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fish Mongery";
    long_desc = "Fish Mongery.\n";
    dest_dir = ({
        "domain/original/area/vesla/room803", "north",
    });
}
