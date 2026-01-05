inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mage's House";
    long_desc = "Mage's House.\n";
    dest_dir = ({
        "domain/original/area/vesla/room398", "east",
        "domain/original/area/vesla/room206", "south",
    });
}
