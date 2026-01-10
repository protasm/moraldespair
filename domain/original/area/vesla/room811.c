inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hardware Store";
    long_desc = "Hardware Store\n";
    dest_dir = ({
        "domain/original/area/vesla/room163", "west",
    });
}
