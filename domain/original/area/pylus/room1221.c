inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Operating room";
    long_desc = "Operating room.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1220", "west",
    });
}
