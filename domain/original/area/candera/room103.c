inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "pitted turn";
    long_desc = "A low basin of ash and grit sits where the ground once stood higher. Wind has piled sand against one side, leaving the other scoured bare.\n";
    dest_dir = ({
        "domain/original/area/candera/room102", "north",
        "domain/original/area/candera/room104", "south",
        "domain/original/area/candera/room999", "east",
        "domain/original/area/candera/room998", "west",
    });
}
