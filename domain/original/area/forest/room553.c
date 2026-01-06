inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room550", "west",
        "domain/original/area/forest/room565", "south",
        "domain/original/area/forest/room552", "southwest",
        "domain/original/area/forest/room554", "northeast",
        "domain/original/area/forest/room564", "east",
        "domain/original/area/forest/room549", "north",
    });
}
