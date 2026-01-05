inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Warrior's Walk";
    long_desc = "Warrior's Walk.\n";
    dest_dir = ({
        "domain/original/area/candera/room58", "north",
        "domain/original/area/candera/room60", "south",
        "domain/original/area/candera/room967", "west",
    });
}
