inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hall of Bacchus";
    long_desc = "Hall of Bacchus.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1214", "east",
    });
}
