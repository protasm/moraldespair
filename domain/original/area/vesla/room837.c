inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Open Air Market:";
    long_desc = "Open Air Market:\n";
    dest_dir = ({
        "domain/original/area/vesla/room422", "west",
    });
}
