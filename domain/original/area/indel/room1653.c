inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mudball Arena Entrance";
    long_desc = "Mudball Arena Entrance.\n";
    dest_dir = ({
        "domain/original/area/indel/room1583", "up",
    });
}
