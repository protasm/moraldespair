inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Abandoned Building";
    long_desc = "PHASE0: abandoned building";
    dest_dir = ({
        "domain/original/area/vesla/room139", "east",
    });
}

