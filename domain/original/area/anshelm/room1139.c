inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western Spire Stairwell";
    long_desc = "Western Spire Stairwell.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1138", "down",
        "domain/original/area/anshelm/room1140", "up",
    });
}
