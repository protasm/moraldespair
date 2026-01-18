inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Darkened Crossing";
    long_desc = "Two streets meet in a spread of fractured stone, their lines still clear beneath the dust. A collapsed corner wall exposes a dark room open to the weather.";
    dest_dir = ({
        "domain/original/area/vesla/room185", "west",
        "domain/original/area/vesla/room177", "south",
        "domain/original/area/vesla/room179", "north",
    });
}

