inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Lower eastern stairwell";
    long_desc = "PHASE0: Lower Eastern Stairwell";
    dest_dir = ({
        "domain/original/area/vesla/room759", "southwest",
        "domain/original/area/vesla/room761", "up",
    });
}

