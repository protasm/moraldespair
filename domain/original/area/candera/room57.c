inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "drifted platform";
    long_desc = "Scattered piers suggest a once-long span, now broken into bays. Wind has piled sand against one side, leaving the other scoured bare.\n";
    dest_dir = ({
        "domain/original/area/candera/room1", "north",
        "domain/original/area/candera/room58", "south",
        "domain/original/area/candera/room964", "east",
        "domain/original/area/candera/room963", "west",
    });
}
