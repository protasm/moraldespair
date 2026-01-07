inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You let up on the ropes, and the counterweight slowly glides you down the";
    long_desc = "You let up on the ropes, and the counterweight slowly glides you down the.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1305", "southwest",
        "domain/original/area/barb-caves/room1303", "up",
        "domain/original/area/barb-caves/room1320", "east",
        "domain/original/area/barb-caves/room1311", "north",
    });
}
