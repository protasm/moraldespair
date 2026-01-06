inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East wing";
    long_desc = "East wing.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1369", "west",
        "domain/original/area/pylus/room1372", "south",
    });
}
