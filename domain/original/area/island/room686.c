inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "RIIS";
    long_desc = "RIIS.\n";
    dest_dir = ({
        "domain/original/area/island/room687", "down",
        "domain/original/area/island/room677", "south",
    });
}
