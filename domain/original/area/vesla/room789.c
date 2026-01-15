inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tether Line";
    long_desc = "A line of rotted posts stands uneven, each marked by rust streaks. The\n"
                + "floor is hard and bare, broken only by a drift of grit.\n";
    dest_dir = ({
        "domain/original/area/vesla/room773", "north",
    });
}

