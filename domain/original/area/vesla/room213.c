inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South End of Via Sacra";
    long_desc = "South End of Via Sacra";
    dest_dir = ({
        "domain/original/area/vesla/room212", "south",
        "domain/original/area/vesla/room399", "east",
        "domain/original/area/vesla/room214", "north",
    });
}
