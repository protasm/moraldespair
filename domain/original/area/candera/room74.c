inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Clansmen Way";
    long_desc = "Clansmen Way.\n";
    dest_dir = ({
        "domain/original/area/candera/room1018", "north",
        "domain/original/area/candera/room1019", "south",
        "domain/original/area/candera/room73", "east",
        "domain/original/area/candera/room75", "west",
    });
}
