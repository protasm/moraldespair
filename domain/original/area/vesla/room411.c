inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Vesla Times Press Office";
    long_desc = "Vesla Times Press Office.\n";
    dest_dir = ({
        "domain/original/area/vesla/room410", "east",
        "domain/original/area/vesla/room123", "south",
    });
}
