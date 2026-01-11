inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mercantile Guild Office";
    long_desc = "PHASE0: a business office";
    dest_dir = ({
        "domain/original/area/vesla/room837", "east",
        "domain/original/area/vesla/room155", "west",
    });
}

