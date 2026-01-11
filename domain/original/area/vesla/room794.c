inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A small building.";
    long_desc = "PHASE0: formerly a sewer entrance (exit down)";
    dest_dir = ({
        "domain/original/area/vesla/room792", "south",
    });
}

