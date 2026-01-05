inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Warrior's Walk";
    long_desc = "Warrior's Walk.\n";
    dest_dir = ({
        "domain/original/area/candera/room60", "north",
        "domain/original/area/candera/room62", "south",
        "domain/original/area/candera/room970", "west",
    });
}
