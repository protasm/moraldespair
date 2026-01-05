inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Main Street";
    long_desc = "South Main Street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room820", "west",
        "domain/original/area/vesla/room152", "south",
        "domain/original/area/vesla/room154", "north",
    });
}
