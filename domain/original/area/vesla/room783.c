inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Small paddock";
    long_desc = "PHASE0: stables (hay, wood, horse-tending tools, etc.)";
    dest_dir = ({
        "domain/original/area/vesla/room778", "northeast",
        "domain/original/area/vesla/room779", "east",
        "domain/original/area/vesla/room777", "north",
    });
}

