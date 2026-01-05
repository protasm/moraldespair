inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Anshelmish Keep's drawbridge";
    long_desc = "Anshelmish Keep's drawbridge.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room255", "east",
        "domain/original/area/anshelm/room1196", "west",
    });
}
