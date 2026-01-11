inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "First Floor";
    long_desc = "PHASE0: a government building";
    dest_dir = ({
        "domain/original/area/vesla/room833", "up",
        "domain/original/area/vesla/room822", "down",
        "domain/original/area/vesla/room832", "west",
    });
}

