inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A sandy beachhead";
    long_desc = "A sandy beachhead.\n";
    dest_dir = ({
        "domain/original/area/island/room605", "south",
        "domain/original/area/island/room623", "west",
        "domain/original/area/island/room626", "east",
        "domain/original/area/island/room607", "north",
    });
}
