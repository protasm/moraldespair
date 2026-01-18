inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bottom floor of the silo";
    long_desc = "Bottom floor of the silo";
    dest_dir = ({
        "domain/original/area/vesla/room873", "up",
    });
}
