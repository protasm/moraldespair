inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Killing Room";
    long_desc = "Killing Room.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1153", "east",
        "domain/original/area/anshelm/room1137", "west",
    });
}
