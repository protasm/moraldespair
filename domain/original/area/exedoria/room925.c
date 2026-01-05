inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dwarven armoury";
    long_desc = "Dwarven armoury.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room920", "west",
    });
}
