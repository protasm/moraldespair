inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Beitel Straad at the Promenade";
    long_desc = "Beitel Straad at the Promenade.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1150", "west",
        "domain/original/area/anshelm/room414", "east",
        "domain/original/area/anshelm/room1169", "north",
    });
}
