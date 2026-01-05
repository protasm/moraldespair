inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Armourer's Shack";
    long_desc = "Armourer's Shack.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room270", "north",
    });
}
