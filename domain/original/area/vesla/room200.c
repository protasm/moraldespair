inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Street of the Bells and Zand Boulevard";
    long_desc = "PHASE0: Junction of Ruined Street and Hidden Boulevard";
    dest_dir = ({
        "domain/original/area/vesla/room201", "west",
        "domain/original/area/vesla/room199", "north",
    });
}

