inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The royal dressing room";
    long_desc = "The royal dressing room.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1398", "east",
    });
}
