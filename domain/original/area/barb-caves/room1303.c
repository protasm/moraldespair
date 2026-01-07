inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You let up on the ropes, and the counterweight slowly glides you down the";
    long_desc = "You let up on the ropes, and the counterweight slowly glides you down the.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1304", "down",
        "domain/original/area/barb-caves/room1302", "up",
    });
}
