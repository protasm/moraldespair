inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A clearing in the forest";
    long_desc = "A clearing in the forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room540", "west",
        "domain/original/area/forest/room553", "south",
        "domain/original/area/forest/room550", "southwest",
        "domain/original/area/forest/room548", "northeast",
        "domain/original/area/forest/room554", "east",
        "domain/original/area/forest/room541", "north",
    });
}
