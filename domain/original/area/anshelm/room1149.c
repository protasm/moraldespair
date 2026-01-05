inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Base of the Eastern Stairwell";
    long_desc = "Base of the Eastern Stairwell.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1148", "up",
    });
}
