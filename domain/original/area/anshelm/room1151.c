inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern Spire Stairwell";
    long_desc = "Eastern Spire Stairwell.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1149", "down",
        "domain/original/area/anshelm/room1152", "up",
    });
}
