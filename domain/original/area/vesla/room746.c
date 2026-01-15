inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Store Room";
    long_desc = "PHASE0: dormitory where NPC students and athletes lived";
    dest_dir = ({
        "domain/original/area/vesla/room745", "west",
    });
}

