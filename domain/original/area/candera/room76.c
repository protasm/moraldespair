inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Clansmen Way";
    long_desc = "Clansmen Way.\n";
    dest_dir = ({
        "domain/original/area/candera/room86", "north",
        "domain/original/area/candera/room78", "south",
        "domain/original/area/candera/room75", "east",
        "domain/original/area/candera/room77", "west",
    });
}
