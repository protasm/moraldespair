inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gatehouse Barracks";
    long_desc = "Gatehouse Barracks.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1146", "east",
        "domain/original/area/anshelm/room1144", "west",
    });
}
