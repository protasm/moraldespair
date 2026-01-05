inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Farmer's Smith";
    long_desc = "Farmer's Smith.\n";
    dest_dir = ({
        "domain/original/area/candera/room989", "east",
        "domain/original/area/candera/room58", "west",
    });
}
