inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Deora's Outfitters";
    long_desc = "PHASE0: a player-owned armory";
    dest_dir = ({
        "domain/original/area/vesla/room231", "south",
    });
}

