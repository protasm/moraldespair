inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Clansmen Way";
    long_desc = "Clansmen Way.\n";
    dest_dir = ({
        "domain/original/area/candera/room977", "north",
        "domain/original/area/candera/room976", "south",
        "domain/original/area/candera/room97", "east",
        "domain/original/area/candera/room95", "west",
    });
}
