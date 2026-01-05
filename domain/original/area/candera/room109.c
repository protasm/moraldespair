inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Phaekads Flat";
    long_desc = "Phaekads Flat.\n";
    dest_dir = ({
        "domain/original/area/candera/room110", "north",
        "domain/original/area/candera/room108", "south",
    });
}
