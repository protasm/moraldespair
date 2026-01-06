inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = "Silver Street.\n";
    dest_dir = ({
        "domain/original/area/balin/room615", "south",
        "domain/original/area/balin/room689", "east",
        "domain/original/area/balin/room617", "north",
    });
}
