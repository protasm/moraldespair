inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mausoleum entrance";
    long_desc = "Mausoleum entrance.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1207", "west",
    });
}
