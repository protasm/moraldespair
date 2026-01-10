inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Quiet Room";
    long_desc = "Quiet Room\n";
    dest_dir = ({
        "domain/original/area/vesla/room405", "north",
    });
}
