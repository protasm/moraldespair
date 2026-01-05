inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "6 Feet Under";
    long_desc = "6 Feet Under.\n";
    dest_dir = ({
        "domain/original/area/candera/room97", "south",
        "domain/original/area/candera/room977", "west",
    });
}
