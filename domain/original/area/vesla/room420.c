inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Old Temple";
    long_desc = "PHASE0: players came here for healing if no player healers were available";
    dest_dir = ({
        "domain/original/area/vesla/room130", "north",
    });
}

