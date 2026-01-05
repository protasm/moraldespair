inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple of Earth";
    long_desc = "Temple of Earth.\n";
    dest_dir = ({
        "domain/original/area/candera/room104", "west",
        "domain/original/area/candera/room1126", "up",
    });
}
