inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Second floor of whore house.";
    long_desc = "Second floor of whore house.\n";
    dest_dir = ({
        "domain/original/area/vesla/room828", "south",
        "domain/original/area/vesla/room826", "west",
        "domain/original/area/vesla/room829", "up",
        "domain/original/area/vesla/room824", "down",
        "domain/original/area/vesla/room827", "north",
    });
}
