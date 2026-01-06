inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rotunda of Peace";
    long_desc = "Rotunda of Peace.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1382", "east",
    });
}
