inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Royal Throne Room";
    long_desc = "Royal Throne Room.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1261", "east",
    });
}
