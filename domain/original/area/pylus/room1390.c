inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of Ithsma street";
    long_desc = "End of Ithsma street.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1389", "west",
    });
}
