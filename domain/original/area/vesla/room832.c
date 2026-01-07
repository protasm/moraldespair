inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Soot-Stained Interior";
    long_desc = "Soot and dust drift in the stale air. The floor is split and buckled, as though immense weight and heat pressed down at once.\n";
    dest_dir = ({
        "domain/original/area/vesla/room831", "east",
    });
}
