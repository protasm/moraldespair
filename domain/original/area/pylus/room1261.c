inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Administrative hallway";
    long_desc = "Administrative hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1262", "west",
        "domain/original/area/pylus/room1259", "east",
        "domain/original/area/pylus/room1391", "south",
    });
}
