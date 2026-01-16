inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Between the towers";
    long_desc = "PHASE0: Between two towers";
    dest_dir = ({
        "domain/original/area/vesla/room753", "south",
        "domain/original/area/vesla/room755", "north",
    });
}

