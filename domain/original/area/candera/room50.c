inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northwest Corner";
    long_desc = "Northwest Corner.\n";
    dest_dir = ({
        "domain/original/area/candera/room49", "south",
        "domain/original/area/candera/room51", "east",
    });
}
