inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A sandy beachhead";
    long_desc = "A sandy beachhead.\n";
    dest_dir = ({
        "domain/original/area/balin/room605", "south",
        "domain/original/area/balin/room623", "west",
        "domain/original/area/balin/room626", "east",
        "domain/original/area/balin/room607", "north",
    });
}
