inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Paved intersection";
    long_desc = "Paved intersection.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room388", "east",
        "domain/original/area/exedoria/room386", "northwest",
        "domain/original/area/exedoria/room527", "south",
    });
}
