inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle stables";
    long_desc = "PHASE0: stables (hay, wood, horse-tending tools, etc.)";
    dest_dir = ({
        "domain/original/area/vesla/room784", "south",
        "domain/original/area/vesla/room774", "west",
        "domain/original/area/vesla/room776", "east",
        "domain/original/area/vesla/room785", "north",
    });
}

