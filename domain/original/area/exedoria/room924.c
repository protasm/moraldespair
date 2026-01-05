inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dwarven Ambassador's office";
    long_desc = "Dwarven Ambassador's office.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room920", "south",
    });
}
