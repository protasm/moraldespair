inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pylus road checkpoint";
    long_desc = "Pylus road checkpoint.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1289", "east",
        "domain/original/area/pylus/room1215", "west",
    });
}
