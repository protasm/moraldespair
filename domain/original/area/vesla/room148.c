inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "A line of cracked flagstones stretches west, fractured\n"
                + "by roots.\n"
                + "A low parapet crumbles toward a silent channel, its edge\n"
                + "washed bare.\n";
    dest_dir = ({
        "domain/original/area/vesla/room147", "west",
        "domain/original/area/vesla/room149", "east",
        "domain/original/area/vesla/room840", "north",
    });
}
