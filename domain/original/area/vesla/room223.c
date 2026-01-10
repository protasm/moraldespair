inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Medieval Mounts";
    long_desc = "Medieval Mounts";
    dest_dir = ({
        "domain/original/area/vesla/room224", "west",
        "domain/original/area/vesla/room222", "east",
        "domain/original/area/vesla/room120", "north",
    });
}
