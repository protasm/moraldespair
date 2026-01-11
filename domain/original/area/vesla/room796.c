inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "An alley";
    long_desc = "An alley\n";
    dest_dir = ({
        "domain/original/area/vesla/room814", "south",
        "domain/original/area/vesla/room795", "west",
        "domain/original/area/vesla/room231", "east",
        "domain/original/area/vesla/room961", "north",
    });
}
