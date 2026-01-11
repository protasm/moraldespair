inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Candle Shop";
    long_desc = "PHASE0: NPC-owned business";
    dest_dir = ({
        "domain/original/area/vesla/room214", "west",
    });
}

