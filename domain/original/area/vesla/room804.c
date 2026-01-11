inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fish Mongery";
    long_desc = "PHASE0: an NPC-owned shop";
    dest_dir = ({
        "domain/original/area/vesla/room803", "north",
    });
}

