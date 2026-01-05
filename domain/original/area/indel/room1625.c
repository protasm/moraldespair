inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Quicksilver Delivery Service";
    long_desc = "Quicksilver Delivery Service.\n";
    dest_dir = ({
        "domain/original/area/indel/room1405", "east",
    });
}
