inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Chapel of Peace";
    long_desc = "Chapel of Peace.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1382", "north",
    });
}
