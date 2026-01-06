inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Garden clearing";
    long_desc = "Garden clearing.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1251", "west",
        "domain/original/area/pylus/room1249", "south",
    });
}
