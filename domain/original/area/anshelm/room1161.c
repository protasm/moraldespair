inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Killing Room";
    long_desc = "Killing Room.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1160", "east",
        "domain/original/area/anshelm/room1162", "west",
    });
}
