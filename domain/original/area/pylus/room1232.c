inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gay house";
    long_desc = "Gay house.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1231", "north",
    });
}
