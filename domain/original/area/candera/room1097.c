inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Canderan Guard House";
    long_desc = "Canderan Guard House.\n";
    dest_dir = ({
        "domain/original/area/candera/room82", "east",
    });
}
