inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pitted Turn";
    long_desc = "A low basin of ash and grit sits where the ground once stood higher. Wind has piled sand against one side, leaving the other scoured bare.";
    dest_dir = ({
        "domain/original/area/candera/room34", "east",
        "domain/original/area/candera/room36", "west",
    });
}
