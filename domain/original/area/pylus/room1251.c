inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entry to akademos";
    long_desc = "Entry to akademos.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1250", "east",
        "domain/original/area/pylus/room1374", "west",
    });
}
