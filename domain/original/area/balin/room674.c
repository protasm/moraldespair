inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "City Pastry Shop";
    long_desc = "City Pastry Shop.\n";
    dest_dir = ({
        "domain/original/area/balin/room612", "west",
    });
}
