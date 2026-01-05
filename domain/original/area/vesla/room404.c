inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple of Amaterasu";
    long_desc = "Temple of Amaterasu.\n";
    dest_dir = ({
        "domain/original/area/vesla/room405", "east",
        "domain/original/area/vesla/room403", "west",
    });
}
