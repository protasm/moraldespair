inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The storage room";
    long_desc = "PHASE0: a storage room for the blacksmith to the west";
    dest_dir = ({
        "domain/original/area/vesla/room771", "west",
    });
}

