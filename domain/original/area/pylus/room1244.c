inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Herbarium";
    long_desc = "Herbarium.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1228", "east",
        "domain/original/area/pylus/room1245", "south",
    });
}
