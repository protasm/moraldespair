inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Iola way";
    long_desc = "Iola way.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1249", "west",
        "domain/original/area/pylus/room1252", "east",
        "domain/original/area/pylus/room1226", "south",
    });
}
