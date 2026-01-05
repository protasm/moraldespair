inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western Stairwell";
    long_desc = "Western Stairwell.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1137", "up",
    });
}
