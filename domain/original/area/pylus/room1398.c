inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Royal Chambers";
    long_desc = "The Royal Chambers.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1399", "west",
        "domain/original/area/pylus/room1396", "south",
    });
}
