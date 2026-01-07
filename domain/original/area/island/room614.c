inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A Grand Plaza";
    long_desc = "A Grand Plaza.\n";
    dest_dir = ({
        "domain/original/area/island/room613", "south",
        "domain/original/area/island/room678", "west",
        "domain/original/area/island/room677", "east",
        "domain/original/area/island/room615", "north",
    });
}
