inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gateway to Middle Bailey";
    long_desc = "Gateway to Middle Bailey.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room241", "south",
        "domain/original/area/anshelm/room243", "north",
    });
}
