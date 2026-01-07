inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Repair Shop";
    long_desc = "Repair Shop.\n";
    dest_dir = ({
        "domain/original/area/island/room620", "west",
    });
}
