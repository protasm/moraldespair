inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The inner ward";
    long_desc = "The inner ward\n";
    dest_dir = ({
        "domain/original/area/vesla/room755", "south",
        "domain/original/area/vesla/room757", "north",
    });
}
