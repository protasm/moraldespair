inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Smoke House";
    long_desc = "PHASE0: NPC workers labored here";
    dest_dir = ({
        "domain/original/area/vesla/room210", "south",
    });
}

