inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Vesla Post Office";
    long_desc = "PHASE0: \"post office\" for in-game player email";
    dest_dir = ({
        "domain/original/area/vesla/room126", "south",
    });
}

