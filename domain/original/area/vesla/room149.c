inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West River street";
    long_desc = "West River street\n";
    dest_dir = ({
        "domain/original/area/vesla/room150", "east",
        "domain/original/area/vesla/room148", "west",
    });
}
