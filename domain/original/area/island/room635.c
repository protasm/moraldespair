inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road";
    long_desc = "Balin Road.\n";
    dest_dir = ({
        "domain/original/area/island/room719", "northwest",
        "domain/original/area/island/room717", "south",
        "domain/original/area/island/room718", "northeast",
        "domain/original/area/island/room610", "east",
        "domain/original/area/island/room636", "west",
    });
}
