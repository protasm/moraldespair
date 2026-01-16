inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Middle eastern stairwell";
    long_desc = "PHASE0: Middle Eastern Stairwell";
    dest_dir = ({
        "domain/original/area/vesla/room762", "southwest",
        "domain/original/area/vesla/room760", "down",
        "domain/original/area/vesla/room763", "up",
    });
}

