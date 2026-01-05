inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Butcher Shop:";
    long_desc = "Butcher Shop:.\n";
    dest_dir = ({
        "domain/original/area/candera/room103", "west",
    });
}
