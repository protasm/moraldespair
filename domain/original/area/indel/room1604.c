inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Soldiers' Tent";
    long_desc = "Soldiers' Tent.\n";
    dest_dir = ({
        "domain/original/area/indel/room1603", "west",
    });
}
