inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Office of the Magistrate";
    long_desc = "Office of the Magistrate.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1259", "south",
    });
}
