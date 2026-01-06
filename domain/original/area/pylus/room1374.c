inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Akademos";
    long_desc = "Akademos.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1251", "east",
    });
}
