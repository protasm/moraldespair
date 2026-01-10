inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Old Office";
    long_desc = "Old Office";
    dest_dir = ({
        "domain/original/area/vesla/room847", "west",
    });
}
