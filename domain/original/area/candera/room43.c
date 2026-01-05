inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Wall Guard Station";
    long_desc = "West Wall Guard Station.\n";
    dest_dir = ({
        "domain/original/area/candera/room44", "north",
        "domain/original/area/candera/room42", "south",
        "domain/original/area/candera/room1033", "west",
    });
}
