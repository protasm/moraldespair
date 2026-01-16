inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stink Alley Way";
    long_desc = "PHASE0: A Stinky Alleyway";
    dest_dir = ({
        "domain/original/area/vesla/room805", "south",
        "domain/original/area/vesla/room803", "west",
        "domain/original/area/vesla/room799", "east",
        "domain/original/area/vesla/room807", "north",
    });
}

