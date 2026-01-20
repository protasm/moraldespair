inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wall Road West";
    long_desc = "The road ends against the inner wall, where the paving breaks into rubble and a shallow drift of sand. The wall looms close, its lower stones stained dark by old runoff and moss.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room171", "east",
        "chapter/prologue/area/ruined/room168", "west",
    });
}
