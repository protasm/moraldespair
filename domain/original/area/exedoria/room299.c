inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eithel Sirion";
    long_desc = "Eithel Sirion.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room300", "south",
        "domain/original/area/exedoria/room290", "north",
    });
}
