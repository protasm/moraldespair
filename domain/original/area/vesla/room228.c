inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Walk";
    long_desc  = "A brittle silence fills this ruined space. Burnt stone and warped metal gleam faintly, scarred by intense flames.\n";

    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "north",
        "domain/original/area/vesla/room227",   "south",
        "domain/original/area/vesla/room232",   "east",
        "domain/original/area/vesla/room231",   "west",
    });
}

