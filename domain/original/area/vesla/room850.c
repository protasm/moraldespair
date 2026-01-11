inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Howling Wolf Inn";
    long_desc = "PHASE0: inn";
    dest_dir = ({
        "domain/original/area/vesla/room142", "west",
        "domain/original/area/vesla/room852", "east",
        "domain/original/area/vesla/room851", "north",
    });
}

