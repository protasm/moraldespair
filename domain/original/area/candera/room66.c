inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pitted Turn";
    long_desc = "A low basin of ash and grit sits where the ground once stood higher. Wind has\npiled sand against one side, leaving the other scoured bare.\n";
    dest_dir = ({
        "domain/original/area/candera/room65", "north",
        "domain/original/area/candera/room67", "south",
    });
}
