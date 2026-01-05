inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "In Rohan's bedroom";
    long_desc = "In Rohan's bedroom.\n";
    dest_dir = ({
        "domain/original/area/vesla/room869", "down",
        "domain/original/area/vesla/room871", "up",
    });
}
