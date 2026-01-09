inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Drifted Platform";
    long_desc = "Scattered piers suggest a once-long span, now broken into bays. Wind has piled\nsand against one side, leaving the other scoured bare.\n";
    dest_dir = ({
        "domain/original/area/candera/room85", "down",
    });
}
