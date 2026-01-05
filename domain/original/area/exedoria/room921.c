inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dwarven watchtower";
    long_desc = "Dwarven watchtower.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room920", "down",
        "domain/original/area/exedoria/room922", "north",
    });
}
