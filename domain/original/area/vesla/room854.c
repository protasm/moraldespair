inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Spice Merchant";
    long_desc = "PHASE0: NPC-owned business";
    dest_dir = ({
        "domain/original/area/vesla/room139", "west",
    });
}

