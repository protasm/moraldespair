inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West End of Balin Road";
    long_desc = "West End of Balin Road.\n";
    dest_dir = ({
        "domain/original/area/balin/room638", "west",
        "domain/original/area/balin/room720", "northeast",
        "domain/original/area/balin/room636", "east",
        "domain/original/area/balin/room723", "south",
    });
}
