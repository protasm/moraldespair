inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Iola bridge";
    long_desc = "Iola bridge.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1230", "southwest",
        "domain/original/area/pylus/room1231", "east",
        "domain/original/area/pylus/room1228", "north",
    });
}
