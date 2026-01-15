inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "An empty lot.";
    long_desc = "PHASE0: empty lot";
    dest_dir = ({
        "domain/original/area/vesla/room192", "north",
    });
}

