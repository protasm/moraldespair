inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Canopy Trail";
    long_desc = "Canopy Trail.\n";
    dest_dir = ({
        "domain/original/area/preserve/room439", "west",
        "domain/original/area/preserve/room437", "east",
        "domain/original/area/preserve/room440", "south",
    });
}
