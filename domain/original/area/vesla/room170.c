inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wall Road West";
    long_desc = "The road ends against the inner wall, where the paving breaks into\n"
              + "rubble and a shallow drift of sand. The wall looms close, its\n"
              + "lower stones stained dark by old runoff and moss.\n";
    dest_dir = ({
        "domain/original/area/vesla/room171", "east",
        "domain/original/area/vesla/room168", "west",
    });
}
