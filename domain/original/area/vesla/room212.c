inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Via Sacra and River Street";
    long_desc = "Intersection of Via Sacra and River Street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room211", "west",
        "domain/original/area/vesla/room213", "north",
    });
}
