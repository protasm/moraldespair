inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Consort's chambers";
    long_desc = "The Consort's chambers.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1397", "south",
    });
}
