inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Abandoned Warehouse";
    long_desc = "Abandoned Warehouse";
    dest_dir = ({
        "domain/original/area/vesla/room198", "west",
    });
}
