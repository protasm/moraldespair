inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = "Silver Street.\n";
    dest_dir = ({
        "domain/original/area/island/room610", "south",
        "domain/original/area/island/room713", "east",
        "domain/original/area/island/room612", "north",
    });
}
