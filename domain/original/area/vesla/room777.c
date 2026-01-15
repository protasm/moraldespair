inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Small paddock";
    long_desc = "PHASE0: stables (hay, wood, horse-tending tools, etc.)";
    dest_dir = ({
        "domain/original/area/vesla/room779", "southeast",
        "domain/original/area/vesla/room783", "south",
        "domain/original/area/vesla/room776", "west",
        "domain/original/area/vesla/room778", "east",
        "domain/original/area/vesla/room780", "north",
    });
}

