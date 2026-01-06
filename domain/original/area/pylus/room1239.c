inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gymnasium foyer";
    long_desc = "Gymnasium foyer.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1240", "west",
        "domain/original/area/pylus/room1230", "east",
        "domain/original/area/pylus/room1241", "south",
    });
}
