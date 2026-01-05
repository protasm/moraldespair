inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Beitel Straad";
    long_desc = "Beitel Straad.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1188", "east",
        "domain/original/area/anshelm/room1186", "west",
    });
}
