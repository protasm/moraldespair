inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Canopy Trail";
    long_desc = "Canopy Trail.\n";
    dest_dir = ({
        "domain/original/area/preserve/room496", "west",
        "domain/original/area/preserve/room439", "east",
        "domain/original/area/preserve/room446", "north",
    });
}
