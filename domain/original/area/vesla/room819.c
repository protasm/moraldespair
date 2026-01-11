inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guild/Shop Space for rent";
    long_desc = "PHASE0: a vacant commercial lot";
    dest_dir = ({
        "domain/original/area/vesla/room152", "east",
    });
}

