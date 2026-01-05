inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Alchemist's Shop";
    long_desc = "Alchemist's Shop.\n";
    dest_dir = ({
        "domain/original/area/candera/room79", "west",
    });
}
