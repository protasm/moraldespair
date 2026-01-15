inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Effortlessly, you scale the brick wall and drop into a garden on the opposite";
    long_desc = "PHASE0: a garden of a home to the west, which no longer exists";
    dest_dir = ({
        "domain/original/area/vesla/room168", "east",
    });
}

