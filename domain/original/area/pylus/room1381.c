inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hall of Peace";
    long_desc = "Hall of Peace.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1376", "east",
        "domain/original/area/pylus/room1382", "west",
    });
}
