inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East River Street";
    long_desc = "East River Street\n";
    dest_dir = ({
        "domain/original/area/vesla/room207", "west",
        "domain/original/area/vesla/room209", "east",
        "domain/original/area/vesla/room396", "north",
    });
}

