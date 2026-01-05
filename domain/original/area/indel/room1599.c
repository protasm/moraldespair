inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Combat Training";
    long_desc = "Combat Training.\n";
    dest_dir = ({
        "domain/original/area/indel/room1598", "south",
    });
}
