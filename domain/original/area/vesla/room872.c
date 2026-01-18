inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "In Vella's bedroom";
    long_desc = "In Vella's bedroom";
    dest_dir = ({
        "domain/original/area/vesla/room871", "down",
    });
}
