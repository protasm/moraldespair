inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Iola square";
    long_desc = "Iola square.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1289", "west",
        "domain/original/area/pylus/room1227", "south",
        "domain/original/area/pylus/room1225", "north",
    });
}
