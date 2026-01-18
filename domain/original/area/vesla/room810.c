inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tailor's Shop";
    long_desc = "Tailor's Shop";
    dest_dir = ({
        "domain/original/area/vesla/room162", "west",
    });
}
