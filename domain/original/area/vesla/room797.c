inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A dingy alley";
    long_desc = "A dingy alley\n";
    dest_dir = ({
        "domain/original/area/vesla/room795", "south",
        "domain/original/area/vesla/room798", "north",
    });
}
