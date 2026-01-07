inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road";
    long_desc = "Balin Road.\n";
    dest_dir = ({
        "domain/original/area/island/room670", "south",
        "domain/original/area/island/room662", "west",
        "domain/original/area/island/room664", "east",
        "domain/original/area/island/room671", "north",
    });
}
