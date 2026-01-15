inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle stables";
    long_desc = "PHASE0: stables (hay, wood, horse-tending tools, etc.)";
    dest_dir = ({
        "domain/original/area/vesla/room789", "south",
        "domain/original/area/vesla/room770", "west",
        "domain/original/area/vesla/room774", "east",
        "domain/original/area/vesla/room788", "north",
    });
}

