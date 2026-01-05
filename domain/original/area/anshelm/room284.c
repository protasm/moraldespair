inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Kirsch Lane";
    long_desc = "Kirsch Lane.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room283", "west",
        "domain/original/area/anshelm/room285", "east",
        "domain/original/area/anshelm/room1327", "north",
    });
}
