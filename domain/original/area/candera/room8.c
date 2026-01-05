inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northeast Corner";
    long_desc = "Northeast Corner.\n";
    dest_dir = ({
        "domain/original/area/candera/room9", "south",
        "domain/original/area/candera/room7", "west",
    });
}
