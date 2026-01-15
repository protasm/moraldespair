inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Flea Market";
    long_desc = "PHASE0: this was a player-owned weapons and armor shop";
    dest_dir = ({
        "domain/original/area/vesla/room796", "north",
    });
}

