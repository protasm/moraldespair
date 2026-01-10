inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Street of the Bells";
    long_desc = "Street of the Bells";
    dest_dir = ({
        "domain/original/area/vesla/room203", "west",
        "domain/original/area/vesla/room201", "east",
        "domain/original/area/vesla/room844", "south",
    });
}
