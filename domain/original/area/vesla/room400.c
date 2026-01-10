inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bell maker's shop";
    long_desc = "Bell maker's shop";
    dest_dir = ({
        "domain/original/area/vesla/room214", "east",
    });
}
