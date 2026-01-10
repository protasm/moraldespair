inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dormitory Hallway";
    long_desc = "Dormitory Hallway";
    dest_dir = ({
        "domain/original/area/vesla/room748", "up",
        "domain/original/area/vesla/room190", "south",
        "domain/original/area/vesla/room747", "east",
        "domain/original/area/vesla/room745", "north",
    });
}
