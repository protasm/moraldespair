inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "A line of cracked flagstones stretches west, fractured by roots. A low parapet\n"
              + "crumbles toward a silent channel, its edge washed bare.\n";
    dest_dir = ({
        "domain/original/area/vesla/room147", "west",
        "domain/original/area/vesla/room149", "east",
        "domain/original/area/vesla/room840", "north",
    });
}
