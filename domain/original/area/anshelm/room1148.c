inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern Stairwell";
    long_desc = "Eastern Stairwell.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1149", "down",
    });
}
