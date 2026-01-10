inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Park Street and Via Sacra";
    long_desc = "Intersection of Park Street and Via Sacra\n";
    dest_dir = ({
        "domain/original/area/vesla/room220", "south",
        "domain/original/area/vesla/room118", "west",
        "domain/original/area/vesla/room116", "east",
        "domain/original/area/vesla/room226", "north",
    });
}
