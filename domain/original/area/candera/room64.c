inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "broken passage";
    long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire-blackened patches run along the base of the walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room63", "north",
        "domain/original/area/candera/room65", "south",
        "domain/original/area/candera/room427", "east",
        "domain/original/area/candera/room429", "west",
    });
}
