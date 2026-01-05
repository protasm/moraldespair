inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silk Shop";
    long_desc = "Silk Shop.\n";
    dest_dir = ({
        "domain/original/area/candera/room61", "east",
    });
}
