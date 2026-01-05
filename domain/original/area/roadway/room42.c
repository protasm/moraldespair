inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to Anshelm";
    long_desc = "Entrance to Anshelm.\n";
    dest_dir = ({
        "domain/original/area/roadway/room41", "south",
        "domain/original/area/anshelm/room235", "city",
    });
}
