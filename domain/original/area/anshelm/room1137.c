inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Second Floor Landing";
    long_desc = "Second Floor Landing.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1136", "down",
        "domain/original/area/anshelm/room1142", "east",
        "domain/original/area/anshelm/room1138", "up",
    });
}
