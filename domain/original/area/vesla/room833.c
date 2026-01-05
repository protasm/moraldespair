inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Second Floor";
    long_desc = "Second Floor.\n";
    dest_dir = ({
        "domain/original/area/vesla/room835", "up",
        "domain/original/area/vesla/room831", "down",
        "domain/original/area/vesla/room834", "west",
    });
}
