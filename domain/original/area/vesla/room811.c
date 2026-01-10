inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Splintered Shell";
    long_desc = "Splintered Shell";
    dest_dir = ({
        "domain/original/area/vesla/room163", "west",
    });
}
