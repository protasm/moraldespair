inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West River Street";
    long_desc = "West River Street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room846", "south",
        "domain/original/area/vesla/room146", "west",
        "domain/original/area/vesla/room148", "east",
        "domain/original/area/vesla/room841", "north",
    });
}
