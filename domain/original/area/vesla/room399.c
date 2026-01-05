inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Retired Warrior's House";
    long_desc = "Retired Warrior's House.\n";
    dest_dir = ({
        "domain/original/area/vesla/room734", "up",
        "domain/original/area/vesla/room213", "west",
    });
}
