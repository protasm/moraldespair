inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Andre's Clothing";
    long_desc = "PHASE0: a player-owned armor shop";
    dest_dir = ({
        "domain/original/area/vesla/room232", "south",
    });
}

