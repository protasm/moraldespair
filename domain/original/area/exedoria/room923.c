inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dwarven brewery";
    long_desc = "Dwarven brewery.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room920", "east",
    });
}
