inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Elven Embassy checkpoint";
    long_desc = "Elven Embassy checkpoint.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room314", "north",
    });
}
