inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West wing";
    long_desc = "West wing.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1369", "east",
    });
}
