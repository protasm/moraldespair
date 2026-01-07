inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = "Silver Street.\n";
    dest_dir = ({
        "domain/original/area/island/room690", "west",
        "domain/original/area/island/room616", "south",
        "domain/original/area/island/room618", "north",
    });
}
