inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rising Phoenix";
    long_desc = "PHASE0: a player-owned distillery";
    dest_dir = ({
        "domain/original/area/vesla/room796", "south",
    });
}

