inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Turkish Bath";
    long_desc = "Turkish Bath.\n";
    dest_dir = ({
        "domain/original/area/balin/room703", "south",
        "domain/original/area/balin/room708", "east",
        "domain/original/area/balin/room701", "north",
    });
}
