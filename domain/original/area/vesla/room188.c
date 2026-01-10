inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scholar's Way";
    long_desc = "Scholar's Way";
    dest_dir = ({
        "domain/original/area/vesla/room189", "west",
        "domain/original/area/vesla/room187", "east",
        "domain/original/area/vesla/room738", "north",
    });
}

