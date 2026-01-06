inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road";
    long_desc = "Balin Road.\n";
    dest_dir = ({
        "domain/original/area/balin/room719", "northwest",
        "domain/original/area/balin/room717", "south",
        "domain/original/area/balin/room718", "northeast",
        "domain/original/area/balin/room610", "east",
        "domain/original/area/balin/room636", "west",
    });
}
