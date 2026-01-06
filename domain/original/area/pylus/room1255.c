inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ithsma street";
    long_desc = "Ithsma street.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1253", "west",
        "domain/original/area/pylus/room1389", "east",
        "domain/original/area/pylus/room1256", "north",
    });
}
