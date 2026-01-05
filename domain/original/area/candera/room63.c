inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Canderan Well";
    long_desc = "Canderan Well.\n";
    dest_dir = ({
        "domain/original/area/candera/room62", "north",
        "domain/original/area/candera/room64", "south",
        "domain/original/area/candera/room94", "east",
        "domain/original/area/candera/room72", "west",
    });
}
