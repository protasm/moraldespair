inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Crumbling Wreck";
    long_desc = "Crumbling Wreck";
    dest_dir = ({
        "domain/original/area/vesla/room224", "west",
        "domain/original/area/vesla/room222", "east",
        "domain/original/area/vesla/room120", "north",
    });
}
