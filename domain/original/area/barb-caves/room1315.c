inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Your left arm is now in full health.";
    long_desc = "Your left arm is now in full health.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1314", "northwest",
    });
}
