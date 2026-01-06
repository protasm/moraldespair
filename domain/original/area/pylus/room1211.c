inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Master stonemason's";
    long_desc = "Master stonemason's.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1209", "south",
    });
}
