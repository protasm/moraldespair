inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bedchamber";
    long_desc = "Bedchamber.\n";
    dest_dir = ({
        "domain/original/area/balin/room701", "east",
        "domain/original/area/balin/room699", "west",
    });
}
