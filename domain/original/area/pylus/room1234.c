inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Short house";
    long_desc = "Short house.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1233", "north",
    });
}
