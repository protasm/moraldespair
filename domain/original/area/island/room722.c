inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wheelwright";
    long_desc = "Wheelwright.\n";
    dest_dir = ({
        "domain/original/area/island/room636", "northeast",
    });
}
