inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Howling Wolf Inn";
    long_desc = "PHASE0: inn";
    dest_dir = ({
        "domain/original/area/vesla/room850", "south",
    });
}

