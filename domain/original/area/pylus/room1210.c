inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Apprentice's";
    long_desc = "Apprentice's.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1209", "north",
    });
}
