inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western end of Beitel Straad";
    long_desc = "Western end of Beitel Straad.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1150", "east",
        "domain/original/area/anshelm/room1164", "north",
    });
}
