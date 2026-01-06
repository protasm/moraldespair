inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Doorway";
    long_desc = "Doorway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1225", "east",
        "domain/original/area/pylus/room1364", "west",
    });
}
