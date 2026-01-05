inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Treetop Bedroom";
    long_desc = "Treetop Bedroom.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room909", "down",
    });
}
