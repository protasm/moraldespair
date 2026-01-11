inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Abandoned Store";
    long_desc = "PHASE0: abandoned store";
    dest_dir = ({
        "domain/original/area/vesla/room199", "west",
    });
}

