inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You pass through the door and it closes and locks behind you.";
    long_desc = "You pass through the door and it closes and locks behind you.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1297", "east",
    });
}
