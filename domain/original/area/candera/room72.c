inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Clansmen Way";
    long_desc = "Clansmen Way.\n";
    dest_dir = ({
        "domain/original/area/candera/room429", "south",
        "domain/original/area/candera/room63", "east",
        "domain/original/area/candera/room73", "west",
    });
}
