inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Alley";
    long_desc = "PHASE0: a dead-end alley";
    dest_dir = ({
        "domain/original/area/vesla/room188", "south",
    });
}

