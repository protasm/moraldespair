inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dwarven Home";
    long_desc = "Dwarven Home.\n";
    dest_dir = ({
        "domain/original/area/balin/room653", "north",
    });
}
