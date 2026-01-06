inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ithsma street";
    long_desc = "Ithsma street.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1252", "west",
        "domain/original/area/pylus/room1255", "east",
        "domain/original/area/pylus/room1254", "south",
    });
}
