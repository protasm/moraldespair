inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Before the Dwarven Embassy";
    long_desc = "Before the Dwarven Embassy.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room317", "south",
        "domain/original/area/exedoria/room920", "north",
    });
}
