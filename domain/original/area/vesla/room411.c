inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Vesla Times Press Office";
    long_desc = "PHASE0: NPC-owned newspaper printer";
    dest_dir = ({
        "domain/original/area/vesla/room410", "east",
        "domain/original/area/vesla/room123", "south",
    });
}


