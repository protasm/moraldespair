inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Caravan Road";
    long_desc = "Caravan Road";
    dest_dir = ({
        "domain/original/area/vesla/room172", "south",
        "domain/original/area/vesla/room232", "west",
        "domain/original/area/vesla/room736", "east",
        "domain/original/area/vesla/room174", "north",
    });
}

