inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tall house";
    long_desc = "Tall house.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1233", "south",
    });
}
