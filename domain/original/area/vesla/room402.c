inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Do-it-Yourself Distiller";
    long_desc = "PHASE0: NPC-owned distillery";
    dest_dir = ({
        "domain/original/area/vesla/room216", "east",
    });
}

