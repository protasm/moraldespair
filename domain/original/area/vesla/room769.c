inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The well";
    long_desc = "PHASE0: a well";
    dest_dir = ({
        "domain/original/area/vesla/room765", "southwest",
        "domain/original/area/vesla/room771", "east",
        "domain/original/area/vesla/room768", "west",
    });
}

