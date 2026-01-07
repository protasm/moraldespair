inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple Plaza";
    long_desc = "Temple Plaza.\n";
    dest_dir = ({
        "domain/original/area/island/room715", "west",
        "domain/original/area/island/room671", "east",
        "domain/original/area/island/room662", "south",
    });
}
