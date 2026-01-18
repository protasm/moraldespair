inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Leaning Way";
    long_desc = "Two aligned walls hint at a corridor now filled with drifted sand. Loose stones shift with each step, exposing darker layers below.";
    dest_dir = ({
        "domain/original/area/candera/room973", "north",
    });
}
