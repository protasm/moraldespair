inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Chamber of Commerce";
    long_desc = "PHASE0: a government building";
    dest_dir = ({
        "domain/original/area/vesla/room831", "east",
    });
}

