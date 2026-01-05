inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Velvet Unicorn";
    long_desc = "Velvet Unicorn.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room288", "south",
    });
}
