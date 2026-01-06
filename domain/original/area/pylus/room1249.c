inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Garden entry";
    long_desc = "Garden entry.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1248", "east",
        "domain/original/area/pylus/room1250", "north",
    });
}
