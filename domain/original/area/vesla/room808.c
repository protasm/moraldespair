inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Livery";
    long_desc = "Livery\n";
    dest_dir = ({
        "domain/original/area/vesla/room809", "up",
        "domain/original/area/vesla/room161", "west",
    });
}
