inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rhian's Potion Shop";
    long_desc = "Rhian's Potion Shop.\n";
    dest_dir = ({
        "domain/original/area/balin/room615", "east",
    });
}
