inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "City Hall";
    long_desc = "City Hall\n";
    dest_dir = ({
        "domain/original/area/vesla/room156", "east",
        "domain/original/area/vesla/room831", "up",
    });
}
