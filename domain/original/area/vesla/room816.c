inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle Bridge";
    long_desc = "PHASE0: A high-level NPC castle guard blocked the way south";
    dest_dir = ({
        "domain/original/area/vesla/room151", "north",
    });
}

