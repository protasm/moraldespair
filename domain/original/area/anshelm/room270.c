inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Kasernegade";
    long_desc = "Kasernegade.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room271", "west",
        "domain/original/area/anshelm/room269", "east",
        "domain/original/area/anshelm/room1199", "south",
    });
}
