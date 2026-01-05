inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Player Appreciation Week Discussions";
    long_desc = "Player Appreciation Week Discussions.\n";
    dest_dir = ({
        "domain/original/area/indel/room1627", "north",
    });
}
