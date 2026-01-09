inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Leaning Way";
    long_desc = "Two aligned walls hint at a corridor now filled with drifted sand. Loose stones\nshift with each step, exposing darker layers below.\n";
    dest_dir = ({
        "domain/original/area/candera/room5", "east",
        "domain/original/area/candera/room3", "west",
    });
}
