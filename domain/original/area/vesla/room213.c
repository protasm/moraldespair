inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Southern End";
    long_desc = "The way thins into broken stones, the once- straight line sagging. Fallen trim and damp rubble gather at the end of the road.";
    dest_dir = ({
        "domain/original/area/vesla/room212", "south",
        "domain/original/area/vesla/room399", "east",
        "domain/original/area/vesla/room214", "north",
    });
}
