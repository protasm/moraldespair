inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Warrior's Walk";
    long_desc = "Warrior's Walk.\n";
    dest_dir = ({
        "domain/original/area/candera/room1", "north",
        "domain/original/area/candera/room58", "south",
        "domain/original/area/candera/room964", "east",
        "domain/original/area/candera/room963", "west",
    });
}
