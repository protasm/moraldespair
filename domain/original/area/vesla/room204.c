inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Street of the Bells";
    long_desc = "PHASE0: Ruined Street";
    dest_dir = ({
        "domain/original/area/vesla/room203", "east",
        "domain/original/area/vesla/room140", "west",
    });
}

