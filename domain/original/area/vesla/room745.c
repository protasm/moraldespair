inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dormitory Kitchen";
    long_desc = "PHASE0: dormitory where NPC students and athletes lived";
    dest_dir = ({
        "domain/original/area/vesla/room746", "east",
        "domain/original/area/vesla/room741", "south",
    });
}

