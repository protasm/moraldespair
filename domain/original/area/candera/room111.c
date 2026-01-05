inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Phaekads Flat:";
    long_desc = "Phaekads Flat:.\n";
    dest_dir = ({
        "domain/original/area/candera/room112", "north",
        "domain/original/area/candera/room110", "south",
        "domain/original/area/candera/room996", "east",
    });
}
