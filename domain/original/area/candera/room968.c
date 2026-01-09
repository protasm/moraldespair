inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "broken passage";
    long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire-blackened patches run along the base of the walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room60", "east",
    });
}
