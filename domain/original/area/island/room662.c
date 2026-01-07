inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road";
    long_desc = "Balin Road.\n";
    dest_dir = ({
        "domain/original/area/island/room661", "west",
        "domain/original/area/island/room663", "east",
        "domain/original/area/island/room672", "north",
    });
}
