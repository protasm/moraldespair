inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bright house";
    long_desc = "Bright house.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1235", "south",
    });
}
