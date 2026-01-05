inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Caravan Road";
    long_desc = "Caravan Road.\n";
    dest_dir = ({
        "domain/original/area/vesla/room116", "south",
        "domain/original/area/vesla/room226", "west",
        "domain/original/area/vesla/room735", "east",
        "domain/original/area/vesla/room173", "north",
    });
}
