inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northern niche";
    long_desc = "Northern niche.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1289", "south",
    });
}
