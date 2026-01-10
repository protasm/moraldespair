inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tea Shop";
    long_desc = "Tea Shop";
    dest_dir = ({
        "domain/original/area/vesla/room157", "east",
    });
}
