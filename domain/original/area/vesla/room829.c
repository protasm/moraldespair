inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Robert's room";
    long_desc = "PHASE0: a brothel";
    dest_dir = ({
        "domain/original/area/vesla/room825", "down",
    });
}

