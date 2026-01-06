inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Soylent Green";
    long_desc = "Soylent Green.\n";
    dest_dir = ({
        "domain/original/area/balin/room613", "east",
    });
}
